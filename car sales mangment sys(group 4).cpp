#include <iostream>
#include<iomanip>
using namespace std;

struct Node {
    string name;
    string model;
    int price;
    Node* left;
    Node* right;
};

Node* createNode(string name, string model, int price) {
    Node* node = new Node();
    node->name = name;
    node->model = model;
    node->price = price;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, string name, string model, int price) {
    if (root == NULL) {
        return createNode(name, model, price);
    }
    if (price <= root->price) {
        root->left = insert(root->left, name, model, price);
    } else if (price > root->price) {
        root->right = insert(root->right, name, model, price);
    }
    return root;
}

void searchTree(Node* root,string key){
    if (root == NULL) {
        return;
    }
    searchTree(root->left,key);
    if(root->name == key)
     cout<<setiosflags(ios::left)
     << setw(20)
     <<root->name
     << setw(20)
     << root->model
     <<setw(20)
     << root->price
     << endl;
    searchTree(root->right,key);
}

void printTreeAsend(Node* root) {
    if (root == NULL) {
        return;
    }
    printTreeAsend(root->left);
     cout<<setiosflags(ios::left)
     << setw(20)
     <<root->name
     << setw(20)
     << root->model
     <<setw(20)
     << root->price
     << endl;
    printTreeAsend(root->right);
}

void printTreeDesend(Node* root) {
    if (root == NULL) {
        return;
    }
    printTreeDesend(root->right);
     cout<<setiosflags(ios::left)
     << setw(20)
     <<root->name
     << setw(20)
     << root->model
     <<setw(20)
     << root->price
     << endl;
    printTreeDesend(root->left);
}

void add(Node* root){
while (true) {
        cout << "Enter the Name to Insert or Type 'q' to Exit: ";
        string name;
        cin >> name;

        if (name == "q"||name == "Q") {
            break;
        }

        cout << "Enter Model: ";
        string model;
        cin >> model;

        cout << "Enter price: ";
        int price;
        cin >> price;

        Node* node = insert(root, name, model, price);
    }


}

void look(Node* root){
    system("cls");
    cout << "Enter the Name to Search or Type 'q' to Exit: ";
    string name;
    cin >> name;
    searchTree(root,name);
}

void admin(Node* root){
    system("cls");
    char choice;
    do{
    cout<<"ABCD CAR IMPORT CO.LTD \nplease specify your choice"<<endl;
    cout<<"1: Insert"<<endl;
    cout<<"2: Search"<<endl;
    cout<<"3: List"<<endl;
    int n;
    cin>>n;
    switch(n){
        case 1:
            system("cls");
            add(root);
            cout<<"---------------------------------------------------"<<endl;
            break;
        case 2:
            system("cls");
            look(root);
            cout<<"---------------------------------------------------"<<endl;
            break;
        case 3:
            system("cls");
            cout<<"ABCD CAR IMPORT CO.LTD \nplease specify your choice"<<endl;
            cout<<"1: Asending"<<endl;
            cout<<"2: Desending"<<endl;
            int p;
            cin>>p;
            if(p == 1){
            cout<<setiosflags(ios::left)
            <<setw(20)
            <<"Name"
            <<setw(20)
            <<"Model"
            <<setw(20)
            <<"Price"
            <<endl<<"___________________________________________________"<<endl;
            printTreeAsend(root);
            cout<<"---------------------------------------------------"<<endl;
            }
            else if(p == 2){
            cout<<setiosflags(ios::left)
            <<setw(20)
            <<"Name"
            <<setw(20)
            <<"Model"
            <<setw(20)
            <<"Price"
            <<endl<<"___________________________________________________"<<endl;
            printTreeDesend(root);
            cout<<"---------------------------------------------------"<<endl;
            }
            else{
            cout<<"invalid option";
            break;
            }
            break;
        default :
            cout<<"invalid option";
            break;
    }
    cout<<"DO YOU WANT TO PERFORM ANOTHER OPRETION YES( Y or y) NO(N or n or hit any other key except y or Y) : "<<endl;
    cin>>choice;
    system("cls");
    }while(choice== 'Y'|| choice=='y');
}

void user(Node* root){
    system("cls");
    char choice;
    do{
    cout<<"ABCD CAR IMPORT CO.LTD \nplease specify your choice"<<endl;
    cout<<"1: Search"<<endl;
    cout<<"2: List"<<endl;
    int n;
    cin>>n;
    switch(n){
        case 1:
            system("cls");
            look(root);
            cout<<"---------------------------------------------------"<<endl;
            break;
        case 2:
            system("cls");
            cout<<"ABCD CAR IMPORT CO.LTD \nplease specify your choice"<<endl;
            cout<<"1: Asending"<<endl;
            cout<<"2: Desending"<<endl;
            int p;
            cin>>p;
            if(p == 1){
            cout<<setiosflags(ios::left)
            <<setw(20)
            <<"Name"
            <<setw(20)
            <<"Model"
            <<setw(20)
            <<"Price"
            <<endl<<"___________________________________________________"<<endl;
            printTreeAsend(root);
            cout<<"---------------------------------------------------"<<endl;
            }
            else if(p == 2){
            cout<<setiosflags(ios::left)
            <<setw(20)
            <<"Name"
            <<setw(20)
            <<"Model"
            <<setw(20)
            <<"Price"
            <<endl<<"___________________________________________________"<<endl;
            printTreeDesend(root);
            cout<<"---------------------------------------------------"<<endl;
            }
            else{
            cout<<"invalid option";
            break;
            }
            break;
        default :
            cout<<"invalid option\n";
            break;
    }
    cout<<"DO YOU WANT TO PERFORM ANOTHER OPRETION YES( Y or y) NO(N or n or hit any other key except y or Y) : "<<endl;
    cin>>choice;
    system("cls");
    }while(choice== 'Y'|| choice=='y');
}

void interFace(Node* root){
    cout<<"WELLCOME TO ABCD CAR IMPORT CO.LTD \nplease specify your choice"<<endl;
    cout<<"1: user(for customers )"<<endl;
    cout<<"2: admin(for owners only)"<<endl;
    int key;
    cin>>key;
    switch(key){
    case 1:
       user(root);
       break;
    case 2:
        int p;
        cout<<"Enter your Password(12345) :";
        cin>>p;
        if(p ==12345)
        admin(root);
        break;
    default:
      cout<<"invalid input\n";
      break;
    }
}



int main() {
    Node* root = NULL;
    root = insert(root, "bmw", "Z4", 516894);
    insert(root, "toyota", "HIACE", 89759);
    insert(root, "ford", "MUSTANG", 100000);
    insert(root, "jaguar", "F-TYPE", 225452);
    insert(root, "marcedes", "AMG", 5246);
    insert(root, "chevrolet", "F4", 5545478);
    insert(root, "bughatti", "VEYRON", 4556454);
    insert(root, "volvo", "MW2", 1214555);
    insert(root, "toyota", "HILUX", 74500);
    insert(root, "mazerati", "LEVANTE",124554);
    insert(root, "fiat", "LA PRIMA", 5246);
    insert(root, "volkswagon", "AORF", 5246);

    interFace(root);
}

