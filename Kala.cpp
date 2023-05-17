#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Items Class
class Items
{
public:
    static int IDcounter;
    int Items_ID;
    string item_name;
    double item_price;
    Items()
    {
        Items_ID = ++IDcounter;
    }
    Items(string name, double p) : item_name(name), item_price(p)
    {
        Items_ID = ++IDcounter;
    }
    void virtual display_items(){};
}; // End of Items
int Items::IDcounter = 100;
// Class Household ----for household Items
class household : public Items
{
public:
    string description;
    float rating;

    household(string name, double p, string desc, float r) : Items(name, p)
    {
        this->description = desc;
        this->rating = r;
    }
    void display_items()
    {
        cout << endl;
        cout << "Item:" << item_name << "---Price: " << item_price << " Rs" << endl;
        cout << "Description:" << description << endl;
        cout << "Rating:" << rating << "/5" << endl;
        cout << endl;
    }
}; // end of household

// Accessories class for Accessories Items
class Accessories : public Items
{
public:
    string device_type; // Device on which accessories are used
    float rating;

    Accessories(string name, double p, string type, float ra) : Items(name, p)
    {
        this->device_type = type;
        this->rating = ra;
    }
    void display_items()
    {
        cout << endl;
        cout << "Item name:" << item_name << "---"
             << "Price: " << item_price << " Rs" << endl;
        cout << "Device type:" << device_type << endl;
        cout << "Rating:" << rating << "/5" << endl;
        cout << endl;
    }
};
// end of accessories

//  History class
// TO store the history of buyers and seller
class history
{
public:
    int Quantity_of_items;
    int orderno;
    double price;
    string name_of_item;
    history() {}
    history(int o, double p, string n, int Quan) : orderno(o), price(p), name_of_item(n), Quantity_of_items(Quan)
    {
    }
    void display_history()
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "The Orderno: " << orderno << endl;
        cout << "Item name:" << name_of_item << "-- Price:" << price << endl;
        cout << "Quantity :" << Quantity_of_items << endl;
        cout << "Total Price : " << Quantity_of_items * (price) << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
};
// end of history class

// Customers class ----parent for buyer and seller
class Customers
{
public:
    string name;
    string Address;
    long int phonenumber;
    string password;
    string email;
    Customers() {}
    Customers(string n, string addr, string pass, string email, long int phnum)
    {
        this->name = n;
        this->Address = addr;
        this->password = pass;
        this->email = email;
        this->phonenumber = phnum;
    }
    virtual void display() = 0;
    virtual void history_details() = 0;
    virtual void add_to_history(int o, double p, string n, int) = 0;
    virtual string getacc_type() = 0;
    virtual void adding_items(int) {}
    virtual int total_listed_items() {}
    virtual int listed_items(int) {}
};
// emd of Customers class

// Buyers Class --subclass of Customers class
class buyers : public Customers
{
public:
    int orders_count = 0;
    history buyers_history[5];
    string acc_type = "buyer";
    buyers() {}
    buyers(string n, string addr, string pass, string email, long int phnum) : Customers(n, addr, pass, email, phnum)
    {
    }
    void display()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "Name:" << name << endl;
        cout << "Address: " << Address << endl;
        cout << "Phone Num:" << phonenumber << endl;
        cout << "---------------------------------------------------" << endl;
    }
    void history_details()
    {
        cout << "-------------------------------------------------------------" << endl;
        cout << "Name: " << name << " Total Orders :" << orders_count << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (int i = 0; i < orders_count; i++)
        {
            buyers_history[i].display_history();
            cout << endl;
        }
    }
    void add_to_history(int n, double p, string it_n, int no_it)
    {
        buyers_history[orders_count].orderno = n;
        buyers_history[orders_count].price = p;
        buyers_history[orders_count].name_of_item = it_n;
        buyers_history[orders_count].Quantity_of_items = no_it;
        orders_count++;
    }
    string getacc_type()
    {
        return acc_type;
    }
}; // end of buyers class

// seller class -- subclass of Customers class
class seller : public Customers
{
public:
    string acc_type = "seller";
    int s_items = 0;
    history seller_history[5];
    int seller_items = 0;
    int sell_items_id[5];

    seller() {}
    seller(string n, string addr, string pass, string email, long int phnum) : Customers(n, addr, pass, email, phnum)
    {
    }
    void display()
    {
        cout << "----------------------------------------" << endl;
        cout << "Name:" << name << endl;
        cout << "Address: " << Address << endl;
        cout << "Phone Num:" << phonenumber << endl;
        cout << "----------------------------------------" << endl;
    }
    void add_to_history(int o, double p, string n, int no_it)
    {
        seller_history[s_items].orderno = o;
        seller_history[s_items].price = p;
        seller_history[s_items].name_of_item = n;
        seller_history[s_items].Quantity_of_items = no_it;
        ++s_items;
    }
    void history_details()
    {
        cout << "-------------------------------------------------" << endl;
        cout << "Name: " << name << " Total items  :" << s_items << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < s_items; i++)
        {

            seller_history[i].display_history();
            cout << endl;
        }
    }
    string getacc_type()
    {
        return acc_type;
    }
    void adding_items(int temp)
    {
        sell_items_id[seller_items] = temp;
        seller_items++;
    }
    int listed_items(int no)
    {
        return sell_items_id[no];
    }
    int total_listed_items()
    {
        return seller_items;
    }

}; // end of seller class

// transactions class

class transactions
{
public:
    long int transactionID;
    double amount;
    string name_of_item;
    int Item_ID;
    static int total_transactions;
    transactions() {}
    transactions(long int t_id, string n_of_it, int i, double p) : transactionID(t_id), name_of_item(n_of_it), Item_ID(i), amount(p)
    {
        total_transactions++;
    }
    void display_transaction()
    {
        cout << "---------------------------------------------------------------------------------" << endl;
        cout << "Transaction ID: " << transactionID << " ItemID: " << Item_ID;
        cout << " Amount: " << amount << " Item: " << name_of_item << endl;
        cout << "---------------------------------------------------------------------------------" << endl;
    }
};
// End of transactions class
int transactions::total_transactions = 0;
// Different type pf accounts to create
enum accounttype{
    buyeraccount,selleraccount
};
// Ecommercewebsite Class
class ECommerceWebsite
{
    static ECommerceWebsite *Instance; // singleton pattern
    string Company;
    string Address;
    long int Contactnum;
    ECommerceWebsite()
    {
        Company = "KALA";
        Address = "Hubballi India";
        Contactnum = 315603054;
    }

public:
    Customers *all_cust[20];
    transactions *transactions_of_website[20];
    Items *items_on_web[20];
    static int items_count;
    static int customer_count;
    static int orders_count;
    static long int generateT_id;
    //Singleton pattern 
    static ECommerceWebsite *getInstance() // To get a single Instance of ECommerce Website class
    {
        if (Instance == NULL)
        {
            Instance = new ECommerceWebsite();
        }
        return Instance;
    }
    // Factory Pattern Implementaion
    int  getaccount(accounttype type,string na,string addr,string passw,string eml,long int pno)
    {
        if(type==buyeraccount)
        {
            buyers *newone= new buyers(na, addr, passw, eml, pno);
            add_customers<buyers>((*newone));
            return 1;
        }
        else if(type==selleraccount)
        {
            seller *newsell=new seller(na, addr, passw, eml, pno);
            add_customers<seller>((*newsell));
            return 2;
        }
        else{
            return -1;
        }
        
    }
    template <class C>
    void add_customers(C &d)
    {
        all_cust[customer_count] = &d;
        customer_count++;
    }
    void Display_Ecomm()
    {
        cout << "-------------------" << endl;
        cout << Company << endl;
        cout << "Address:" << Address << endl;
        cout << "Contact details :" << Contactnum << endl;
        cout << "-------------------" << endl;
    }
    void display_customers()
    {
        for (int i = 0; i < customer_count; i++)
        {
            all_cust[i]->display();
        }
    }

    int authentication(string em, string pd)
    {
        for (int i = 0; i < customer_count; i++)
        {
            if (all_cust[i]->email == em && all_cust[i]->password == pd)
            {
                return i;
            }
        }
        return -1;
    }
    void shop_items(int number)
    {
        int Quantity;
        display_items_available();
        int n;
        cout << "Please select item" << endl;
        cin >> n;
        cout << "Quantity:";
        cin >> Quantity;
        cout << "---------------------------------------------------------" << endl;
        cout << "Order Placed successfully for :" << items_on_web[n - 1]->item_name << endl;
        cout << "---------------------------------------------------------" << endl;
        transactions_of_buying_items(number, n - 1, Quantity);
    }
    void transactions_of_buying_items(int n, int it_no, int Q)
    {
        transactions_of_website[orders_count] = new transactions(generateT_id, items_on_web[it_no]->item_name, items_on_web[it_no]->Items_ID,Q*(items_on_web[it_no]->item_price));
        all_cust[n]->add_to_history(orders_count + 1, items_on_web[it_no]->item_price, items_on_web[it_no]->item_name, Q);
        ++orders_count;
        generateT_id += 101;
    }
    template <typename T>
    void adding_items_on_website(T &item)
    {
        items_on_web[items_count] = &item;
        items_count++;
    }
    void display_items_available()
    {
        for (int i = 0; i < items_count; i++)
        {
            cout << i + 1;
            items_on_web[i]->display_items();
        }
    }
};
int ECommerceWebsite::customer_count = 0;
int ECommerceWebsite::items_count = 0;
int ECommerceWebsite::orders_count = 0;
ECommerceWebsite *ECommerceWebsite::Instance = NULL;
long int ECommerceWebsite::generateT_id = 1000120;
// main Function

int main()
{

    ECommerceWebsite *kala = ECommerceWebsite::getInstance();
    kala->Display_Ecomm();
    // Buyer and seller accounts
    buyers b1("Akhil", "banglore", "akhil123", "akhil@gmail.com", 1425034);
    buyers b2("john", "US", "johnny", "jon@gmail.com", 1235462);
    buyers b3("Shashank", "Udupi", "shashank@1001", "shashank@kletech.ac.in", 32460343);
    seller s1("Mishra", "Manglore", "mishra@123", "mish@gmail.com", 1615186);
    seller s2("kamat", "Udupi", "kamat@101", "kamat202@gmail.com", 2646065);
    seller s3("Zara", "Mumbai", "zara@mumbai101", "zaraxmumbai@gmail.com", 20013044);
    kala->add_customers(b1);
    kala->add_customers(b2);
    kala->add_customers(b3);
    kala->add_customers(s1);
    kala->add_customers(s2);
    kala->add_customers(s3);
    // Items(household and Accessories) on website
    household h1("Knife", 500.21, "A household knife", 4);
    household h2("Cutlery", 5200.99, "A beautiful cutlery set", 4.2);
    household h3("Tea set", 200, "A white color tea set", 3);
    household h4("Glass kitchen ware", 200.14, "A beautiful Glass set", 3.95);
    Accessories A1("Mobile Cover", 784.2, "A blue cover for M21", 3.25);
    Accessories A2("Laptop Cover", 1284, "A Hand stiched cover 15inch laptop", 4.25);
    Accessories A3("Mouse pad", 200.99, "A Smooth mouse black color pad", 3.25);
    Accessories A4("Table lamp", 599, "A decorative study lamp", 4);
    // Adding Items on website
    kala->adding_items_on_website<household>(h1);
    kala->adding_items_on_website<household>(h2);
    kala->adding_items_on_website<household>(h3);
    kala->adding_items_on_website<household>(h4);
    kala->adding_items_on_website<Accessories>(A1);
    kala->adding_items_on_website<Accessories>(A2);
    kala->adding_items_on_website<Accessories>(A3);
    kala->adding_items_on_website<Accessories>(A4);
    // SIGN IN and LOGIN
    int log, number;
    long int pno;
    string na, eml, passw, addr;
    while (1)
    {
        cout << "Please Sign In or Login" << endl;
        cout << "1. SIGN IN "
             << "\n"
             << "2. LOGIN IN " << endl;
        cin >> log;
        if (log == 1)
        {
            int b;
            while (1)
            {
                cout << "1.Sign In as buyer\n2.Sign In as seller" << endl;
                cin >> b;
                if (b == 1)
                {

                    cout << "Enter your User name:" << endl;
                    cin >> na;
                    cout << "Enter your Email:";
                    cin >> eml;
                    cout << "Enter your Password(without Whitespaces):";
                    cin >> passw;
                    cout << "Enter Your Phone number:";
                    cin >> pno;
                    cout << "Enter the address or location:";
                    cin >> addr;
                    int accno=kala->getaccount(buyeraccount,na, addr, passw, eml, pno);
                    if(accno==1)
                    {
                    cout << "---------Buyer Account Created--------------" << endl;
                    }
                    else
                    {
                        cout<<"-----Error IN ACCOUNT CREATION-------"<<endl;
                    }
                    number = ECommerceWebsite::customer_count - 1;
                    cout << "Welcome Mr." << kala->all_cust[number]->name << endl;
                    break;
                }
                else if (b == 2)
                {
                    cout << "Enter your full name" << endl;
                    cin >> na;
                    cout << "Enter your Email" << endl;
                    cin >> eml;
                    cout << "Enter your Password(without Whitespaces)" << endl;
                    cin >> passw;
                    cout << "Enter Your Phone number" << endl;
                    cin >> pno;
                    cout << "Enter the addres" << endl;
                    cin >> addr;
                    int acc2=kala->getaccount(selleraccount,na, addr, passw, eml, pno);
                    if(acc2==2)
                    {
                    cout << "--------------Seller Account Created--------------" << endl;
                    cout << "-------You can now sell as well as buy items------" << endl;
                    }
                    number = ECommerceWebsite::customer_count - 1;
                    cout << "Welcome Mr." << kala->all_cust[number]->name << endl;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        else if (log == 2)
        {
            while (1)
            {
                string mail, p;
                cout << "Enter the email address" << endl;
                cin >> mail;
                cout << "Enter the password" << endl;
                cin >> p;
                try
                {
                    number = kala->authentication(mail, p);
                    if (number >= 0)
                    {
                        cout << "-------------------------" << endl;
                        cout << "Successfully Logged In" << endl;
                        cout << "Welcome Mr." << kala->all_cust[number]->name << endl;
                        cout << "-------------------------" << endl;
                        break;
                    }
                    else
                    {
                        throw(5);
                    }
                }
                catch (int i)
                {
                    if (i == 5)
                        cout << "!!! Wrong Password or Email !!!"
                             << "\n"
                             << "Re-enter " << endl;
                }
            }
        }
        else
        {
            cout << " Wrong Choice" << endl;
            continue;
        }

        while (1)
        {
            if (kala->all_cust[number]->getacc_type() == "buyer")
            {
                int n;
                cout << "Press 1 :To shop " << endl;
                cout << "Press 2 :To show history " << endl;
                cout << "Press 3 :To Display Account Details" << endl;
                cout << "Press 4 :To Display all Tarnsactions " << endl;
                cout << "Press 5 :To Exit the Application " << endl;

                cin >> n;
                switch (n)
                {
                case 1:
                    kala->shop_items(number);
                    break;
                case 2:
                    kala->all_cust[number]->history_details();
                    break;
                case 3:
                    kala->all_cust[number]->display();
                    break;
                case 4:
                    for (int k = 0; k < ECommerceWebsite::orders_count; k++)
                    {
                        kala->transactions_of_website[k]->display_transaction();
                    }
                    break;
                case 5:
                    exit(0);
                    break;
                }
            }
            else
            {
                int n, total, id;
                string it_name1, it_name2, desc, M_type;
                double it_price;
                cout << "Press 1 :To shop " << endl;
                cout << "Press 2 :To show history " << endl;
                cout << "Press 3 :To Display Account Details" << endl;
                cout << "Press 4 :To Add Items" << endl;
                cout << "Press 5 :To Dislay all the items Listed on Website" << endl;
                cout << "Press 6 :To Display all the Transactions " << endl;
                cout << "Press 7 :To Exit the Application " << endl;

                cin >> n;
                switch (n)
                {
                case 1:
                    kala->shop_items(number);
                    break;
                case 2:
                    kala->all_cust[number]->history_details();
                    break;
                case 3:
                    kala->all_cust[number]->display();
                    break;
                case 4:
                    int t;
                    cout << "Enter The Item to be added\n1.Household\n2.Accessories" << endl;
                    cin >> t;

                    if (t == 1)
                    {
                        cout << "Enter the Item name:";
                        cin >> it_name1;
                        cout << "Price of Item :";
                        cin >> it_price;
                        cout << "Description :";
                        cin >> desc;
                        household *new_item = new household(it_name1, it_price, desc, 3);
                        kala->all_cust[number]->adding_items(new_item->Items_ID);
                        kala->adding_items_on_website<household>((*new_item));
                        cout << "------------HOUSEHOLD ITEM ADDED SUCCESSFULLY-----------" << endl;
                    }
                    else if (t == 2)
                    {
                        cout << "Enter the Item name:";
                        cin >> it_name2;
                        cout << "Price of Item :";
                        cin >> it_price;
                        cout << "Device type :";
                        cin >> M_type;
                        Accessories *new_acc = new Accessories(it_name2, it_price, M_type, 3);
                        kala->all_cust[number]->adding_items(new_acc->Items_ID);
                        kala->adding_items_on_website<Accessories>((*new_acc));
                        cout << "----------ACCESSORIES ITEM ADDED SUCCESSFULLY-----------" << endl;
                    }
                    else
                    {
                        cout << "WRONG CHOICE" << endl;
                    }
                    break;
                case 5:
                    total = kala->all_cust[number]->total_listed_items();
                    if (total == 0)
                    {
                        cout << "------------------------------" << endl;
                        cout << "NO LISTED ITEMS ON THE WEBSITE" << endl;
                        cout << "------------------------------" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < total; i++)
                        {
                            id = kala->all_cust[number]->listed_items(i);
                            for (int j = 0; j < ECommerceWebsite::items_count; j++)
                            {
                                if (kala->items_on_web[j]->Items_ID == id)
                                {
                                    kala->items_on_web[j]->display_items();
                                }
                            }
                        }
                    }
                    break;
                case 6:
                    for (int k = 0; k < ECommerceWebsite::orders_count; k++)
                    {
                        kala->transactions_of_website[k]->display_transaction();
                    }
                    break;
                case 7:
                    exit(0);
                    break;
                }
            }
        }

        return 0;
    }
}