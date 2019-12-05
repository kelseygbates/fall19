// Kelsey Bates
// p5.cpp
// This assignment will demonstrate my knowledge of hash functions and hash
// tables.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MIN_LENGTH = 5; 
const string FILENAME = "ulyss12.txt";
const int TABLE_SIZE = 35221;

struct Node {
  string word;
  int count;
  Node* next; 
};

string processString(string word);
// Pre: None
// Post: If word is > 5 letters and contains no numbers, it is stripped of
// punctuation and converted to all lowercase
// If word is <= 5 letters or contains numbers, returns empty string

unsigned hashWord(string word);
// Source: Robert Sedgwicks Algorithms in C book
// Pre: None
// Post: Returns an unsigned hash key for use as index of this word in
// the hash table 

int storeWord(string word, Node* hashTable[]);
// Pre: None
// Post: Stores word in new node at it's hashed index in the hash table
// If there is already a record stored at this index, adds a node and links
// to the next field of the current record stored at this index 
// If the word is already present, the count is incremented 
// Returns the number of collisions that occur when inserting this word

int checkCount(string word, Node* hashTable[]);
// Pre: None
// Post: Returns the count of how many times this word appears in the file
// Returns 0 if word is not present in the hash table 

void getStats(Node* hashTable[], int& uniqueWords);
// Pre: None
// Post: Updates collisions and unique words with correct values based on the
// contents of the hash table

void clearHashTable(Node* hashTable[]);
// Pre: None
// Post: Deallocates all memory used for hash table and hash nodes 

int main()
{
  ifstream infile;
  string word;
  int totalWords = 0;
  int uniqueWords = 0;
  int collisions = 0;
  double loadFactor = 0.0;
  Node* hashTable[TABLE_SIZE];

  for(int i = 0; i < TABLE_SIZE; i++) {
    hashTable[i] = nullptr; 
  }
  
  infile.open(FILENAME);
  while(infile >> word) {
    word = processString(word);
    if(word != "") {
      totalWords++; 
      collisions += storeWord(word, hashTable);
    }
  }
  
  getStats(hashTable, uniqueWords);
  loadFactor = static_cast<double>(uniqueWords)
    / static_cast<double>(TABLE_SIZE);
  cout << endl << "Load factor:    " << loadFactor << endl; 
  cout << "Collisions:     " << collisions << endl;
  cout << "Unique words:   " << uniqueWords << endl;
  cout << "Total words:    " << totalWords << endl << endl << endl; 

  cout << "Enter a word more than 5 letters long (q to quit): ";
  cin >> word; 
  while(word != "q") {
    cout << endl << word; 
    word = processString(word);
    cout << " appears " << checkCount(word, hashTable)
         << " times in the file." << endl; 
    cout << endl << "Enter a word more than 5 letters long (q to quit): ";
    cin >> word;
  }
  cout << endl << "Goodbye!" << endl << endl; 

  clearHashTable(hashTable); 
  return 0; 
}

void getStats(Node* hashTable[], int& uniqueWords)
{
  Node* temp; 
  for(int i = 0; i < TABLE_SIZE; i++) {
    temp = hashTable[i];
    if(temp != nullptr) {
      uniqueWords++; 
      while(temp->next != nullptr) {
        temp = temp->next; 
        uniqueWords++;
      }
    } 
  }
}


string processString(string word)
{
  string temp = "";
  int idx = 0;
  bool number = false;
  if(word.length() <= MIN_LENGTH)
    return temp;
  while(word.length() > MIN_LENGTH && ispunct(word[idx])) {
    word.erase(idx, 1); 
  }
  if(word.length() > MIN_LENGTH) {
    idx = word.length() - 1;
    while(idx >= 0 && ispunct(word[idx])) {
      word.erase(idx, 1);
      idx--; 
    }
  }
  if(word.length() > MIN_LENGTH) {
    for(unsigned i = 0; i < word.length(); i++) {
      if(isdigit(word[i])) {
        number = true; 
      }
    }
    if(number)
      return temp;
  }
  if(word.length() > MIN_LENGTH) {
    for(unsigned i = 0; i < word.length(); i++)
      word[i] = tolower(word[i]);
    return word;
  } else {
    return temp; 
  }
}

unsigned hashWord(string word)
{
  unsigned b = 378551;
  unsigned a = 63689;
  unsigned hash = 0;
  unsigned i = 0;
  for(i = 0; i < word.length(); i++) {
    hash = hash * a + (word[i]);
    a = a * b;
  }
  hash = hash % TABLE_SIZE; 
  return hash; 
}

int storeWord(string word, Node* hashTable[])
{
  int collisions = 0;
  unsigned key;
  Node* temp;
  bool done = false; 
  key = hashWord(word);
  if(hashTable[key] == nullptr) {
    hashTable[key] = new Node; 
    hashTable[key]->word = word;
    hashTable[key]->count = 1;
    hashTable[key]->next = nullptr;
  } else if (hashTable[key]->word == word) {
    hashTable[key]->count += 1; 
  } else {
    temp = hashTable[key];
    while(temp->next != nullptr && !done) {
      temp = temp->next;
      collisions++; 
      if(temp->word == word) {
        temp->count++;
        done = true; 
      }
    }
    if(!done) {
      temp->next = new Node;
      temp->next->word = word;
      temp->next->count = 1;
      temp->next->next = nullptr; 
    }
  }
  return collisions; 
}

int checkCount(string word, Node* hashTable[])
{
  int wordCount = 0;
  Node* temp; 
  int key = hashWord(word);
  temp = hashTable[key];
  if(temp != nullptr) {
    if(temp->word == word) 
      wordCount = temp->count;
    else {
      while(temp->next != nullptr) {
        temp = temp->next;
        if(temp->word == word)
          wordCount = temp->count;
      }
    }
  }
  return wordCount; 
}

void clearHashTable(Node* hashTable[])
{
  Node* del;
  Node* temp; 
  for(int i = 0; i < TABLE_SIZE; i++) {
    del = hashTable[i];
    while(del != nullptr) {
      temp = del;
      del = del->next;
      delete temp;
    }
  }
}
