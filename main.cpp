#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Product{
    int id;
    string name;
    int stock;
    float price;
};

Product products[100];
int productCount=0;

bool login(){

    string user,pass;

    cout<<"===== LOGIN =====\n";

    cout<<"Username: ";
    cin>>user;

    cout<<"Password: ";
    cin>>pass;

    if((user=="admin"||user=="staff") && pass=="1234"){
        cout<<"Login Success\n";
        return true;
    }

    cout<<"Invalid Login\n";
    return false;
}

void loadProducts(){

    ifstream file("products.txt");

    while(file>>products[productCount].id
              >>products[productCount].name
              >>products[productCount].stock
              >>products[productCount].price){

        productCount++;
    }

    file.close();
}

void saveProducts(){

    ofstream file("products.txt");

    for(int i=0;i<productCount;i++){

        file<<products[i].id<<" "
            <<products[i].name<<" "
            <<products[i].stock<<" "
            <<products[i].price<<endl;
    }

    file.close();
}

void addProduct(){

    cout<<"ID: ";
    cin>>products[productCount].id;

    cout<<"Name: ";
    cin>>products[productCount].name;

    cout<<"Stock: ";
    cin>>products[productCount].stock;

    cout<<"Price: ";
    cin>>products[productCount].price;

    productCount++;

    saveProducts();

    cout<<"Product Added\n";
}

void viewProducts(){

    cout<<"\n===== INVENTORY =====\n";

    cout<<left<<setw(10)<<"ID"
        <<setw(15)<<"Name"
        <<setw(10)<<"Stock"
        <<setw(10)<<"Price"<<endl;

    for(int i=0;i<productCount;i++){

        cout<<setw(10)<<products[i].id
            <<setw(15)<<products[i].name
            <<setw(10)<<products[i].stock
            <<setw(10)<<products[i].price<<endl;
    }
}

void searchProduct(){

    int id;

    cout<<"Enter ID: ";
    cin>>id;

    for(int i=0;i<productCount;i++){

        if(products[i].id==id){

            cout<<"Name: "<<products[i].name<<endl;
            cout<<"Stock: "<<products[i].stock<<endl;
            cout<<"Price: "<<products[i].price<<endl;

            return;
        }
    }

    cout<<"Product Not Found\n";
}

void deleteProduct(){

    int id;

    cout<<"Enter ID: ";
    cin>>id;

    for(int i=0;i<productCount;i++){

        if(products[i].id==id){

            for(int j=i;j<productCount-1;j++){

                products[j]=products[j+1];
            }

            productCount--;

            saveProducts();

            cout<<"Product Deleted\n";

            return;
        }
    }

    cout<<"Product Not Found\n";
}

void sellProduct(){

    int id,qty;

    cout<<"Enter Product ID: ";
    cin>>id;

    for(int i=0;i<productCount;i++){

        if(products[i].id==id){

            cout<<"Quantity: ";
            cin>>qty;

            if(qty>products[i].stock){

                cout<<"Not Enough Stock\n";
                return;
            }

            float total=qty*products[i].price;

            products[i].stock-=qty;

            ofstream file("sales.txt",ios::app);

            file<<products[i].name<<" "
                <<qty<<" "
                <<total<<endl;

            file.close();

            saveProducts();

            cout<<"Total Sale: "<<total<<endl;

            return;
        }
    }

    cout<<"Product Not Found\n";
}

void lowStock(){

    cout<<"\nLOW STOCK ALERT\n";

    for(int i=0;i<productCount;i++){

        if(products[i].stock<=5){

            cout<<products[i].name
                <<" only "
                <<products[i].stock
                <<" left\n";
        }
    }
}

void salesReport(){

    ifstream file("sales.txt");

    string name;
    int qty;
    float total;

    cout<<"\n===== SALES REPORT =====\n";

    while(file>>name>>qty>>total){

        cout<<"Product: "<<name<<endl;
        cout<<"Quantity: "<<qty<<endl;
        cout<<"Total: "<<total<<endl;
        cout<<"-------------\n";
    }

    file.close();
}

int main(){

    if(!login())
        return 0;

    loadProducts();

    int choice;

    do{

        cout<<"\n===== MENU =====\n";

        cout<<"1 Add Product\n";
        cout<<"2 View Products\n";
        cout<<"3 Search Product\n";
        cout<<"4 Sell Product\n";
        cout<<"5 Delete Product\n";
        cout<<"6 Low Stock Alert\n";
        cout<<"7 Sales Report\n";
        cout<<"8 Exit\n";

        cout<<"Choice: ";

        cin>>choice;

        switch(choice){

            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: searchProduct(); break;
            case 4: sellProduct(); break;
            case 5: deleteProduct(); break;
            case 6: lowStock(); break;
            case 7: salesReport(); break;
        }

    }while(choice!=8);

    return 0;
}