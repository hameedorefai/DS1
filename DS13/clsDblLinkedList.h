#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;




template <class T>
class clsDblLinkedList
{
private:
    // template <typename> Head;
    int _Size = 0;
public:

    class Node
    {
    public:
        T Value;
        Node* Next = nullptr;
        Node* Prev = nullptr;
    };

    Node* Head = NULL;


    void PrintList()
    {
        Node* Current = Head;

        while (Current != NULL) {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << "\n";
    }

    Node* Find(T Value)
    {// Function to find a node with a specific value in the linked list

        // Loop through the linked list until the end is reached (Head becomes NULL)
        Node* Current = Head;
        while (Current != NULL)
        {
            if (Current->Value == Value)
            {
                return Current;
            }
            Current = Current->Next;
        }
        return NULL;
    }

    void InsertAtBeginning(T Value)
    {
        /*
       1-Create a new node with the desired value.
       2-Set the next pointer of the new node to the current head of the list.
       3-Set the previous pointer of the current head to the new node.
       4-Set the new node as the new head of the list.
       */

       // Allocate memory to a node
        Node* NewNode = new Node();

        // Insert the data
        NewNode->Value = Value;

        // Set NewNode's Next pointer to the current head (Head)
        NewNode->Next = Head;
        // Since NewNode is now the head, its Prev pointer should be nullptr
        NewNode->Prev = nullptr;
        ;

        // Update the Prev pointer of the current head, if it exists
        if (Head != nullptr)
            Head->Prev = NewNode;

        // Move head to New Node
        Head = NewNode;

        _Size++;
    }

    void InsertAfter(Node* CurrentNode, T ValueToInsert)
    {
        /*  1 - Create a new node with the desired value.
        2-Set the next pointer of the new node to the next node of the current node.
        3-Set the previous pointer of the new node to the current node.
        4-Set the next pointer of the current node to the new node.
        5-Set the previous pointer of the next node to the new node(if it exists).
        */

        /*if (Head == NULL)
        {
            cout << "Sorry, Node is empty of items. (NULL)\n";
        }*/

        if (CurrentNode == NULL)
        {
            cout << "Item Not Found.\n";
        }
        else
        {
            Node* NewNode = new Node();
            // Set Value in the New Node's Value.
            NewNode->Value = ValueToInsert;

            /* Replacing Node->Next (Node that Next to the Current Node)
               To NewNode->Next To empty it.*/
            NewNode->Next = CurrentNode->Next;

            /* Know we can put The whole NewNode in Node->Next After we
               empty it in the last opperation.*/
            CurrentNode->Next = NewNode;

            // Update the previous pointer of the new node to point to the 'Value' node
            NewNode->Prev = CurrentNode;

            // Update the previous pointer of the node following the new node to point to the new node
            if (NewNode->Next != NULL)
                NewNode->Next->Prev = NewNode;

            _Size++;
        }
    }

    void InsertAtEnd(T ValueToInsert)
    {
        /*
        1-Create a new node with the desired value.
        2-Traverse the list to find the last node.
        3-Set the next pointer of the last node to the new node.
        4-Set the previous pointer of the new node to the last node.
        */

        Node* NewNode = new Node();
        NewNode->Value = ValueToInsert;
        NewNode->Next = NULL;
        NewNode->Prev = NULL;

        if (Head == NULL)
        {

            Head = NewNode;
        }
        else
        {

            Node* Current = Head;
            while (Current->Next != NULL)
            {
                Current = Current->Next;
            }
            Current->Next = NewNode;
            NewNode->Prev = Current;
        }
        _Size++;
    }

    void DeleteNode(Node* DeleteNode)
    {
        /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
        */

        Node* CurrentNode = Head;
        if (DeleteNode == Head)
        {
            Head = Head->Next;
            // Free Node from memory.
            delete DeleteNode;
            _Size--;
            return;
        }
        if (DeleteNode == NULL)
        {
            return;
        }
        while (CurrentNode->Next != NULL)
        {
            if (CurrentNode->Next == DeleteNode)
            {
                CurrentNode->Next = DeleteNode->Next;
                DeleteNode->Next->Prev = CurrentNode;
                delete DeleteNode;// Free Space in memory
                break;
            }
            else
            {
                CurrentNode = CurrentNode->Next;
            }
        }
        _Size--;
    }

    void DeleteFirstNode()
    {
        /*
        1-Store a reference to the head node in a temporary variable.
        2-Update the head pointer to point to the next node in the list.
        3-Set the previous pointer of the new head to NULL.
        4-Delete the temporary reference to the old head node.
        */

        if (Head->Next == NULL)
        {
            Head = NULL;
            // Free Node from memory.
            delete Head;
        }
        else
        {
            Node* Temp = Head;
            Head = Head->Next;
            Head->Prev = NULL;
            delete Temp; // Free Space in memory
        }
        _Size--;
    }

    void DeleteLastNode()
    {
        /*
        1-Traverse the list to find the last node.
        2-Set the next pointer of the second-to-last node to NULL.
        3-Delete the last node.
        */
        if (Head->Next == NULL)
        {
            //Head == NULL;
            DeleteFirstNode();
            return;
        }

        Node* LastNode = Head;
        Node* BeforeLastNode = LastNode;

        while (LastNode->Next != NULL)
        {
            BeforeLastNode = LastNode;
            LastNode = LastNode->Next;
        }
        BeforeLastNode->Next = NULL; // Before this operation, it was pointing to LastNode.
        delete LastNode;// Free Space in memory.
        _Size--;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (Head == NULL);
    }

    void Clear()
    {
        while (Head != NULL)
        {
            DeleteLastNode();
        }
    }

    void Reverse()
    {
        if (Head == NULL)
            return;

        Node* Current = Head;
        Node* Prev = NULL;
        Node* Next = NULL;

        while (Current != NULL)
        {
            Next = Current->Next;
            Current->Next = Prev;
            Prev = Current;
            Current = Next;
        }
        Head = Prev;
    }

    Node* GetNode(int Index)
    {
        if (Index > _Size - 1 || Index < 0)
            return NULL;

        Node* Current = Head;
        for (int i = 0; i < Index; i++)
        {
            Current = Current->Next;
        }
        return Current;
    }

    T GetItem(int Index)
    {
        return GetNode(Index)->Value;
    }

    bool UpdateItem(int Index, T Value)
    {
        Node* N = Find(GetItem(Index));
        if (N != NULL)
            N->Value = Value;
        else
            return 0;
        return 1;
    }

    bool InsertAfter(int Index, T ValueToInsert)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, ValueToInsert);
            return 1;
        }
        return 0;
    }

};

