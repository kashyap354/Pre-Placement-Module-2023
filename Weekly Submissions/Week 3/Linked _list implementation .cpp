class MyLinkedList {
public:
    
    struct Node {
        int data;
        Node* next;
        
        Node(int data) {
            this->data = data;
            next = nullptr;
        }
        
    };
    
    Node* head {nullptr};
    int length {0};
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(head ==nullptr || index>=length)
            return -1;
        // cout<<"len="<<length;
        
        Node* current = head;
        int cnt=0;
        while(current){
            if(index==cnt)
                return current->data;
            
            current=current->next;
            cnt++;
        }
        
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        Node* newnode= new Node(val);
        
        if(head==nullptr) {
            head = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
        length++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        if(length==0){
            addAtHead(val);
        } else {
            Node* newnode= new Node(val);
            Node* current=head, *prev=head;

            while(current){
                prev=current;            
                current=current->next;
            }

            if(prev)
                prev->next=newnode;

            length++;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node *newnode= new Node(val);

        if(index==0){
            addAtHead(val);
        }
        else if(index==length){
            addAtTail(val);    
        }
        else{

            Node *current=head, *prev=head;
            int cnt=0;
            while(current){
                if(index==cnt){
                    prev->next = newnode;
                    newnode->next = current;
                    break;
                }

                prev=current;
                current=current->next;
                cnt++;
            }

            length++;
        }

    }
    
    
    void insertNode(Node* prev, Node* newnode) {
    }
    

    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(index>=length)
            return;
        
        if(index==0){
            head = head->next;
        } else{
         
            Node *current=head, *prev=head;
            int cnt=0;
            while(current){
                if(index==cnt){
                    prev->next = current->next;
                    // delete current;
                    break;
                }

                prev=current;
                current=current->next;
                cnt++;
            }
        }
        length--;
    }
};
