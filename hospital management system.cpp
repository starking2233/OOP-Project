#include <iostream>
#include <cstdlib>
#include <string>
#include<conio.h>

using namespace std;

struct Data {
    string name, address, disease, gender, description;
    int specialRoomNo, age;
};


struct Node {

    Data data;
    Node* next;
};

Data inputPatients()
{
    string name, address, disease, gender, description;
    int specialRoomNo, age;
    Data p;

    cout << "Enter Patient Name: ";
    cin.ignore();//clearing buffer
    getline(cin, name);

    cout << "Enter Patient Address: ";
    getline(cin, address);

    cout << "Enter Patient Disease: ";
    getline(cin, disease);

    cout << "Enter Patient Gender: ";
    getline(cin, gender);

    cout << "Enter Disease Description: ";
    getline(cin, description);

    cout << "Enter Patient Special Room No.: ";
    cin >> specialRoomNo;

    cout << "Enter Patient Age: ";
    cin >> age;

    p.name = name;
    p.address = address;
    p.disease = disease;
    p.gender = gender;
    p.description = description;
    p.specialRoomNo = specialRoomNo;
    p.age = age;

    return p;

}//end of inputPatients function
       Node* insertFront(Node* head, Data data)
        {
           Node* temp = new Node;
           temp->data = data;

           temp->next = head;
           head = temp;
           return head;

       }//end of insertFront Function
	   Node* insert_patient(Node* head, Data data) 
	   {

         Node* temp = new Node;

         temp->data = data;
         temp->next = NULL;

         if (head == NULL)
         {
           head = temp;
           return head;
         }

          Node* last = head;

          while (last->next != NULL)
         {
            last = last->next;
         }

         last->next = temp;

         return head;

       }//end of append function
       Node* searchList(Node* head, Data v) 
	{

    if (head == NULL)
    {
        cout << "Node is empty returning null" << endl;
        return NULL;
    }

    int l = 1;

    while (head->next != NULL && head->data.name != v.name)
    {
        head = head->next;
        ++l;
    }

    cout << "Element found at location " << l << endl;

    return head;

    }//end of searchList function




//==============================================



     Node* searchList(Node* head, string v) 
	 {

       if (head == NULL)
       {
          cout << "Node is empty returning null" << endl;
          return NULL;
       }

        int l = 1;

        while (head->next != NULL && head->data.name != v)
        {
          head = head->next;
          ++l;
        }

        cout << "Element found at location " << l << endl;

        return head;

     }//end of searchList function


//============================================================================
class HMS
{
	public:
		
     void changeNode(Node* head, string data, string newData)
     {
        while (head != NULL)
        {
           if (head->data.name == data)
           {
               head->data.name = newData;
               break;
           }

           head = head->next;
        }
     }//end of changeNode function

     void printLinkedList(Node* head)
     {
        if (head == NULL)
        {
           cout << "Head is null" << endl;
           return;
        }
        cout<<"NAME    \tADDRESS     \tGENDER     \tDISEASE     \tDISCRIPTION     \tAGE      \tROOM NO"<<endl;
        cout<<"---------------------------------------------------------------------------------------"<<endl;
        while (head->next != NULL)
        {
           cout << head->data.name << "\t\t" << head->data.address
                << "\t\t" << head->data.gender << "\t\t" << head->data.disease
                << "\t\t" << head->data.description << "\t\t\t" << head->data.age
                << "\t\t" << head->data.specialRoomNo << endl;
                head = head->next;
        }
       cout << head->data.name << "\t\t" << head->data.address
                << "\t\t" << head->data.gender << "\t\t" << head->data.disease
                << "\t\t" << head->data.description << "\t\t\t" << head->data.age
                << "\t\t" << head->data.specialRoomNo << endl;
                head = head->next;
        
     }//end of printLinkedList function

//========================================



     int listLength(Node* head) 
	 {
       int temp = 0;

       if (head == NULL)
       {
           cout << "Node is empty" << endl;
           return 0;
       }

       while (head->next != NULL)
       {
          ++temp;
          head = head->next;
       }

       return temp + 1;
     }//end of the listLength function

//============================================


     void delElement(Node* head, int loc)
     {
        Node* temp = new Node;

        temp = head;

        if (head == NULL) 
		{

          cout << "Node is null" << endl;
          return;
        }


        for (int i = 1; i <= loc; ++i)
        {
           temp = temp->next;
           if (i < loc) 
		   {
            head = head->next;
           }//end of if statement

        }//end of for statement

        head->next = temp->next;

     }//end of delElement function

//===========================================

	
};


    


int main()
{
	cout<<"*************************GROUP MEMBERS********************************"<<endl;
    cout<<"                         AREEBA IMRAN                                 "<<endl;
    cout<<"                          HAFSA AZRAM                                 "<<endl;
    cout<<"                         AFFIFA HAMEED                                "<<endl;
    cout<<"                        JAVARIA SHAKEEL                               "<<endl;
    cout<<"**********************************************************************"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"                   HOSPITAL MANAGEMENT SYSTEM                         "<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;

    Node* head = NULL;
    Data patient;
    string nameToSearch;
    string oldName, newName;
    HMS h;
    char ch;
    
    do
    {
    int op;
    
    cout<<"\n**************MENU**********************"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"\nEnter your choice"<<endl;
    cout<<"1. Add Patient"<<endl;
    cout<<"2. Insert new patient at front"<<endl;
    cout<<"3. Search patient by name"<<endl;
    cout<<"4. Change patient name"<<endl;
    cout<<"5. Total Patients"<<endl;
    cout<<"6. Remove Patient"<<endl;
    cout<<"7. Print list"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cin>>op;

        switch (op) {
        case 1:
            cout << "Enter Patient Details Below" << endl;
            patient = inputPatients();
            head = insert_patient(head, patient);
            cout<<"Patient Added Successfully!"<<endl;
            break;

        case 2:
             patient = inputPatients();
            head = insertFront(head, patient);
            cout<<"Patient inserted at front"<<endl;
            break;
            

        case 3:
            cout << "Enter name to search patient: ";
            cin.ignore();
            getline(cin, nameToSearch);
            searchList(head, nameToSearch);
            break;

        case 4:

            cin.ignore();
            cout << "Enter old name ";
            getline(cin, oldName);
            cout << "Enter New Name ";
            getline(cin, newName);

            h.changeNode(head, oldName, newName);
            break;

            break;

        case 5:
             cout << "You have " << h.listLength(head) << " Patients in your Hospital." << endl;

            break;

        case 6:
            
               if (h.listLength(head) < 2)
            {
                cout << "Length is less then two.\nTerminating program" << endl;
                exit(1);
            }
            else {
                cout << "Enter location where you want to delete a patient, at least three patients must be in list? ";
                int l;
                cin >> l;
                h.delElement(head, l - 1);
            }//end of else of case 2
            break;

        case 7:
            h.printLinkedList(head);
            break;

        default:
            cout << "Wrong option Selected" << endl;
        }
        cout<<"Do you want to continue?(y/n)"<<endl;
        cin>>ch;
    }while(ch!='n');
    getch();
    return 0;

}
