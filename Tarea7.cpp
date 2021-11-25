#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    void deleteNode(int);
    void deleteNodeRec(nodo **, int);
    void searchNode(int);
    void searchN(nodo *, int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato?";
        cin >> resp;
        if(resp == 'y'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'y');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
}

//funcion que llama a la recursiva de buscar dato

void BinarySearchTree::searchNode(int dato)
{
    searchN(pBinarySearchTree, dato);
}

void BinarySearchTree::searchN(nodo *p, int dato)
{
    if(!p)
        cout << "El dato no está en el árbol" << endl << endl;
    else
        if(dato < p->dato)
            searchN(p->subLeft, dato);
        else
            if(dato > p->dato)
                searchN(p->subRight, dato);
            else
                cout << "Ya llegué al dato" << endl << endl;
}

//función que llama a la función recursiva eliminar dato

void BinarySearchTree::deleteNode(int dato)
{
    deleteNodeRec(&pBinarySearchTree, dato);
}

// Función recursiva que borra un nodo en un
// árbol binario de búsqueda.

void BinarySearchTree::deleteNodeRec(nodo **r, int dato)
{
    nodo *p;

    if(!(*r)) //si se llegó a un NULL.
        cout << "El dato NO está en el árbol" << endl << endl;
    else
        if(dato < (*r)->dato) //Buscar por subárbol izquierdo del nodo.
            deleteNodeRec(&((*r)->subLeft), dato);
        else
            if(dato > (*r)->dato) //Buscar por subárbol derecho del nodo.
                deleteNodeRec(&((*r)->subRight), dato);
            else{ //El borrado del nodo se hace a partir de aquí:
                if(!((*r)->subLeft) && !((*r)->subRight)){ //Si nodo a borrar es una hoja.
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->subLeft) && (*r)->subRight){ //Si el nodo a borrar
                        p = *r; //solo tiene hijo derecho.
                        *r = (*r)->subRight;
                    }
                    else
                        if((*r)->subLeft && !((*r)->subRight)){ //Si nodo a borrar
                            p = *r; //solo tiene hijo
                            *r = (*r)->subLeft; //izquierdo.
                        }
                        else
                            if((*r)->subLeft && (*r)->subRight){ //Si nodo a borrar tiene
                                p = (*r)->subLeft; //dos hijos.
                                if(!p->subRight){
                                    (*r)->dato = p ->dato;
                                    (*r)->subLeft = p->subLeft;
                                }
                                else{
                                    nodo *q;
                                    while(p->subRight){
                                        q = p;
                                        p = p->subRight;
                                    }
                                    (*r)->dato = p->dato;
                                    q->subRight = p->subLeft;
                                }
                            }
                delete p;
            }
}

int main(void)
{
    cout << endl;
    cout << "Binary Search Tree :D" << endl;

    BinarySearchTree objBinarySearchTree;

    cout << "Insertar datos en el arbol:" <<  endl;
    objBinarySearchTree.insertar();

    cout << "Mostrar Pre-orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout << "Mostrar In-Orden: " << endl;
    objBinarySearchTree.showInorder();
    cout << endl;

    cout << "Mostrar Post-Orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    int dato;
    cout << endl << "Buscando dato." << endl;
    cout << "Digite el dato a buscar: ";
    cin >> dato; cin.ignore();
    objBinarySearchTree.searchNode(dato);

    int eliminar;
    cout << endl << "Eliminando dato." << endl;
    cout << "Digite el dato a borrar: ";
    cin >> eliminar; cin.ignore();
    objBinarySearchTree.deleteNode(eliminar);

    objBinarySearchTree.showInorder();
    
    return 0;
}
