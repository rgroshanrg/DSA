void traverse() {
    if(head != NULL) {
        Node* temp = new Node();
        temp = head;
        cout << "\n Nodes : ";
        while(temp != NULL) {
            cout << "\t" << temp->data;
            temp = temp->next;
        }
        delete temp;
    } else {
        cout << "\n List is Empty - (First add a Node)";
    }
}