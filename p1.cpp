// Kelsey Bates
// p1.cpp

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

const string OUTFILE1 = "OutputA.txt";
const string OUTFILE2 = "OutputB.txt";
const int LIST_SIZE = 60;

struct Node {
  int num;
  Node* next;
};

void printList(Node* list, ostream& output);
// Pre: None
// Post: Prints the elements in the list to the output file

void insertNode(Node*& list, int value);
// Inserts node in nondescending order by value
// Pre: On first call, list is nullptr
// Post: A new node with data 'value' is added to the ordered list

void deleteNode(Node*& list, int value);
// Deletes the node containing data 'value' from the list, if it exists
// Pre: None
// Post: Removes the element with data 'value' from the ordered list

int main()
{
  srand(time(0));
  ofstream output;

  Node* head = nullptr;
  cout << endl << "Welcome to my Linked List Programming Assignment!" << endl;
  cout << "I will now demonstrate my knowledge of linked lists by " << endl
       << "completing the following exercises..." << endl;

  cout << endl <<  "Constructing a linked list of size " << LIST_SIZE << endl
       << endl;
  for (int i = 0; i < LIST_SIZE; i++) {
    insertNode(head, rand() % 100 + 1);
  }

  cout << "Printing the contents of the list to the file " << OUTFILE1 << endl
       << endl;
  output.open(OUTFILE1);
  printList(head, output);
  output.close();

  cout << "Deleting the smallest element in the list: " << head->num << endl
       << endl;
  deleteNode(head, head->num);

  Node* current = head;
  while (current->next != nullptr) {
    current = current->next; 
  }
  cout << "Deleting the largest element in the list: " << current->num << endl
       << endl;
  deleteNode(head, current->num);

  current = head; 
  for (int i = 0; i < 10; i++) {
    current = current->next; 
  }
  cout << "Deleting an element from the middle of the list: " << current->num
       << endl << endl;
  deleteNode(head, current->num);

  cout << "Printing the updated list to the file " << OUTFILE2 << endl << endl;
  output.open(OUTFILE2);
  printList(head, output);
  output.close();

  cout << "Deallocating memory used for the list" << endl << endl;
  while (head != nullptr) {
    current = head;
    head = head->next;
    delete current; 
  }

  cout << "All done! Goodbye :)" << endl << endl;
  return 0;
}

void printList(Node* list, ostream& output)
{
  int counter = 0;
  int lineBreak = 15;
  Node* temp = list;
  while (temp != nullptr) {
    output << setw(5) << temp->num;
    temp = temp->next;
    counter++;
    if (counter > 0 && counter % lineBreak == 0)
      output << endl;
  }
  output << endl << endl;
}

void insertNode(Node*& list, int value)
{
  Node* current = nullptr;
  Node* newNode = new Node;
  newNode->num = value;
  //  newNode->next = nullptr;
  if (list == nullptr || list->num > newNode->num) {
    newNode->next = list;
    list = newNode;
  } else {
    current = list;
    while (current->next != nullptr && current->next->num < newNode->num) {
      current = current->next; 
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

void deleteNode(Node*& list, int value)
{
  Node* current = nullptr;
  Node* delPtr = nullptr;
  if (list == nullptr)
    return;
  if (list->num == value) {
    delPtr = list;
    list = list->next;
  } else {
    current = list;
    while (current->next != nullptr && current->next->num != value) {
      current = current->next; 
    }
    delPtr = current->next;
    current->next = current->next->next;
  }
  delete delPtr; 
}
