#include<iostream>
#include<cstring>

class LinkedList{
    struct Node{
        int data;
        Node* next;
        public:
            Node(int d):data(d),next(nullptr){}
    };
    
    Node *head;
    public:
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

        LinkedList():head(nullptr){}
        ~LinkedList(){
            clear();
        }
        void push_front(int data){
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
        
        void push_back(int data){
            Node *newNode = new Node(data);
            if(!head){
                head = newNode;
                return;
            }
            Node *temp = head;
            while(temp->next !=  NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
        
        void reverse(){
            Node *curr = head;
            Node* prev = nullptr;
            
            while(curr){
                Node* next = curr->next;
                curr->next = prev;
                
                prev = curr;
                curr=next;
            }
            head = prev;
        }
        
        bool remove(int val){
            if(!head){
                return false;
            }
            if(head->data == val){
                Node* nodeToDelete = head;
                head = head->next;
                delete nodeToDelete;
                return true;
            }
            Node *curr = head;
            while(curr->next && curr->next->data != val){
                curr=curr->next;
            }
            
            if(curr->next){
                Node *nodeToDelete = curr->next;
                curr->next = curr->next->next;
                delete nodeToDelete;
                return true; 
            }
            return false;
        }
        void print() const {
            Node* temp = head;
            while (temp) {
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
            std::cout << "NULL\n";
        }
        
        void clear(){
            Node *curr = head;
            while(curr){
                Node *next = curr->next;
                delete curr;
                curr = next;
            }
            head = nullptr;
        }
};

int main(){
LinkedList list;
list.push_back(10);
list.push_back(20);
list.push_back(30);
list.push_back(40);

list.print();

list.reverse();
list.print();

list.remove(20);
list.print();

}