/*
Nama Program : exercise-2
Nama         : Sharashena Chairani
NPM          : 14081080022
Tanggal buat : 08 Mei 2019
Deskripsi    : Tree
********************************************/

#include <iostream>
#include <conio.h>
using namespace std;

struct Simpul
{
 int data;
 Simpul* left;
 Simpul* right;
};

void createTree (Simpul* Root){
	Root = NULL;
}

void createSimpul (Simpul* &pBaru)
{
 	pBaru = new Simpul;
 	cout << "Insert a number: "; cin >> pBaru->data;
 	pBaru->left=NULL;
 	pBaru->right=NULL;
}

void insertBST (Simpul* &Root, Simpul* pBaru)
{
 	if (Root == NULL) 
  	Root = pBaru;
 	else if (pBaru->data<Root->data)
  	insertBST(Root->left,pBaru);
 	else if (pBaru->data>=Root->data)
  	insertBST(Root->right,pBaru);
 	else 
  	cout << "Sudah Ada" << endl;
}

void preOrder(Simpul* Root)
{
 	if (Root!=NULL)
 	{
  	cout << Root->data << " ";
  	preOrder(Root->left);
  	preOrder(Root->right);
 	}
}

void inOrder(Simpul* Root)
{
 	if (Root!=NULL)
 	{
  	preOrder(Root->left);
  	cout << Root->data << " ";
  	preOrder(Root->right);
 	}
}

void postOrder(Simpul* Root)
{
 	if (Root!=NULL)
 	{
  	preOrder(Root->left);
  	preOrder(Root->right);
  	cout << Root->data << " ";
 	}
}

int height(Simpul* Root)
{
 	if (Root==NULL) return 0;
 	else
 	{
  	int lHeight = height(Root->left);
  	int rHeight = height(Root->right);
  
  	if (lHeight > rHeight) return (lHeight + 1);
  	else return (rHeight + 1);
 	}
}

void givenLevel(Simpul* Root, int level)
{
 	if (Root == NULL) return;
 	if (level == 1) cout << Root->data << " ";
 	
	 else if (level > 1)
 	{
  	givenLevel(Root->left,level-1);
  	givenLevel(Root->right,level-1);
 }
}

void levelOrder(Simpul* Root)
{
 	int h=height(Root);
 	for (int i=1; i<=h; i++)
 	{
  	cout << i << ": ";
  	givenLevel(Root,i);
  	cout << endl;
 	} 
}

void depthOrder (Simpul* Root)
{
 	int h=height(Root);
 	for (int i=1; i<=h; i++)
 	{
  	cout << i-1 << ": ";
  	givenLevel(Root,i);
  	cout << endl;
 	} 
}

void printChildren(Simpul* Root, Simpul* pBaru)
{
    pBaru = Root;
    if(pBaru!=NULL)
 {
        cout << "Parent Node: " << pBaru->data <<endl;

        if(pBaru->left==NULL)
            cout << "Left Child: NULL" << endl;
        else
            cout << "Left Child: " << pBaru->left->data << endl;
                     
        if(pBaru->right==NULL)
            cout << "Right Child: NULL" << endl;
        else
            cout << "Right Child: " << pBaru->right->data << endl;
        
  		cout<<endl;    
        
  		printChildren(Root->left, pBaru);
        printChildren(Root->right, pBaru);
    }
}

main(){
    Simpul *t,*p;
    int n,pil;
    
	createTree(t);
    cout<<"Masukkan banyak elemen = ";
    cin>>n;
    
	for (int i=0;i<n;i++){
        createSimpul(p);
        insertBST(t,p);
    }
    
	cout<<"Tree telah dibuat"<<endl;
    getch();
    do{
      system("cls");
      cout<<"\nNo| Menu Tree :"<<endl;
      cout<<"\n1.| Insert"<<endl;
      cout<<"\n2.| Preorder"<<endl;
      cout<<"\n3.| Inorder"<<endl;
      cout<<"\n4.| Postorder"<<endl;
      cout<<"\n5.| Kedalaman"<<endl;
      cout<<"\n6.| Level"<<endl;
      cout<<"\n7.| Anak"<<endl;
      cout<<"\n8.| Exit"<<endl;
      cout<<"\n	 | Masukkan pilihan anda : ";
      cin>>pil;
      
      switch(pil){
           case 1 :
                createSimpul(p);
                insertBST(t,p);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
           case 2 :
                cout<<"Pre Order"<<endl;
                preOrder(t);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
           case 3 :
                cout<<"In Order"<<endl;
                inOrder(t);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
           case 4 :
                cout<<"Post Order"<<endl;
                postOrder(t);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
           case 5 :
                cout<<"Kedalaman Tree"<<endl;
                depthOrder(t);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
           case 6 :
                cout<<"Level Tree"<<endl;
                levelOrder(t);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
           case 7 :
                cout<<"Anak Tree"<<endl;
                printChildren(t,p);
                getch();
                cout<<"Klik enter untuk kembali ke menu"<<endl;
                break;
            case 8 :
                exit(0);
                break;
            }
    }while(pil!=8);
}
