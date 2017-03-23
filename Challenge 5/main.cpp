#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;


	//Pokemon rooster works usign a Circularly linked list to store data
	//This represent an element of the linked list
	//It's your job to determine what need to go in there
	typedef struct ListNode{
    int level;
    std::string name;
    std::string type;
    ListNode *nextNode;
	}ListElem;
	//---------------------------------------------------------

	//pfirst points to the first item of the list
	ListElem *pfirst;
	//plast points to the last item of the list
	ListElem *plast;

	// This is an example of the functions you need to implement
	// Feel free to ignore them, but the solution was made implementing those function

	// Insert pokemonName at position pos in linked list
	// First arg is pokemon name, second is pokemon level
	// Third is pokemon Type and last one is the position in the list
	void Insert (std::string name,int level, std::string type, int index, ListElem *L);

	//delete pokemon at position i from the Circularly Linked List
	void Delete(int, ListElem*);

	//Print out all pokemon on the screen
	void printall(ListElem *L);

	//count the number of pokemon in the Circularly Linked List
	int countitem(ListElem *L){
    if (pfirst == NULL){
      return 0;
    }
    else{
      int count = 1;
      ListElem *currentnode = pfirst;
      while (currentnode->nextNode != NULL){
        count++;
        currentnode = currentnode->nextNode;
      }
      return count;
    }
  }

	//Find pokemon with lowest level
	void findmin(ListElem *L);

	//Find pokemon with highest level
	void findmax(ListElem *L);

	//Find pokemon with corresponding name
	void find(ListElem *L,std::string);



	//Empty the Circularly linked List
	void makeEmpty(){
		pfirst=plast=NULL;
	}
  //fonction insert
  void Insert (std::string name,int level, std::string type, int index, ListElem *L){
    if (pfirst == NULL &&  index !=1){
      cout << "position invalide1" << endl;
      return;
    }
    else if (index-1 > countitem(L) || index <= 0){
      cout << "position invalide2" << endl;
      return;
    }
    //insérer en position 1 qund liste vide
    if (pfirst == NULL && index == 1){
      ListNode *newNode = (ListNode*) malloc (sizeof(ListNode));
      newNode->level = level;
      newNode->name = name;
      newNode->type = type;
      newNode->nextNode = NULL;
      pfirst = plast = newNode;
      return;
    }
    //insérer en position 1 quand liste non vide
    if (index == 1){
      ListNode *newNode = (ListNode*) malloc (sizeof(ListNode));
      newNode->level = level;
      newNode->name = name;
      newNode->type = type;
      newNode->nextNode = pfirst;
      pfirst = newNode;
      return;
    }
    //insérer en dernière position
    if (index-1 == countitem(L)){
      ListNode *newNode = (ListNode*) malloc (sizeof(ListNode));
      newNode->level = level;
      newNode->name = name;
      newNode->type = type;
      newNode->nextNode = NULL;
      plast->nextNode = newNode;
      plast = newNode;
      return;
    }
    //insérer en quelquonque position
    else{
      ListNode *newNode = (ListNode*) malloc (sizeof(ListNode));
      newNode->level = level;
      newNode->name = name;
      newNode->type = type;
      ListNode *currentnode = pfirst;
      for (int i = 1; i < index-1; i++){
        currentnode = currentnode->nextNode;
      }
      ListNode *nextNode = currentnode->nextNode;
      currentnode->nextNode = newNode;
      newNode->nextNode = nextNode;
      return;
    }
    return;
  }
  void Delete(int index, ListElem *L){
    if (index <= 0 || index > countitem(L)){
      cout << "index invalide" << endl;
      return;
    }
    //si un seul élement
    if (countitem(L) == 1 && index == 1){
      pfirst = NULL;
      plast = NULL;
      return;
    }
    //delete au debut
    if (index == 1){
      pfirst = pfirst->nextNode;
      return;
    }
    //delete la derniere
    if (index == countitem(L)){
      ListNode *currentnode = pfirst;
      for (int i = 1; i < index-1; i++){
        currentnode = currentnode->nextNode;
      }
      currentnode->nextNode = NULL;
      plast  = currentnode;
    }
    //reste
    else{
      ListNode *currentnode = pfirst;
      for (int i = 1; i < index-1; i++){
        currentnode = currentnode->nextNode;
      }
      ListNode *nextNode = currentnode->nextNode->nextNode;
      currentnode->nextNode = nextNode;
      return;
    }
  }
  void printall(ListElem *L){
    if (pfirst == NULL){
      cout << "liste vide"<< endl;
      return;
    }
    else{
      int count = 1;
      ListElem *currentnode = pfirst;
      while (currentnode->nextNode != NULL){
        cout << count << ". " << currentnode->name << endl;
        cout << "        Type :" << currentnode->type << endl;
        cout << "        Level :" << currentnode->level << endl;
        count++;
        currentnode = currentnode->nextNode;
      }
      cout << count << ". " << currentnode->name << endl;
      cout << "        Type :" << currentnode->type << endl;
      cout << "        Level :" << currentnode->level << endl;
      return;
    }
  }

  void findmin(ListElem *L){
    if (pfirst == NULL){
      cout << "Not Found"<< endl;
      return;
    }
    else{
      ListElem *currentnode = pfirst;
      int minlevel = currentnode->level;
      std::string name = currentnode->name;
      while (currentnode->nextNode != NULL){
        if (currentnode->level < minlevel){
          minlevel = currentnode->level;
          name = currentnode->name;
        }
        currentnode = currentnode->nextNode;
      }
      if (currentnode->level < minlevel){
        minlevel = currentnode->level;
        name = currentnode->name;
      }
      cout << "The pokemon with the lowest level is: " << name << " who is level " << minlevel << endl;
      return;
    }
  }

  void findmax(ListElem *L){
    if (pfirst == NULL){
      cout << " Not Found"<< endl;
      return;
    }
    else{
      ListElem *currentnode = pfirst;
      int maxlevel = currentnode->level;
      std::string name = currentnode->name;
      while (currentnode->nextNode != NULL){
        if (currentnode->level > maxlevel){
          maxlevel = currentnode->level;
          name = currentnode->name;
        }
        currentnode = currentnode->nextNode;
      }
      if (currentnode->level > maxlevel){
        maxlevel = currentnode->level;
        name = currentnode->name;
      }
      cout << "The pokemon with the highest level is: " << name << " who is level " << maxlevel << endl;
      return;
    }
  }
  void find(ListElem *L, std::string name){
    if (pfirst == NULL){
      cout << "Not Found"<< endl;
      return;
    }
    else{
      bool found= false;
      ListElem *currentnode = pfirst;
      while (currentnode->nextNode != NULL){
        if (name == currentnode->name){
          cout<<"Pokemon found : "<< currentnode->name<< " Level : "
          << currentnode->level << " Type : " << currentnode->type << endl;
          found =true;
        }
        currentnode = currentnode->nextNode;
      }
      if (name == currentnode->name){
        cout<<"Pokemon found : "<< currentnode->name<< " Level : "
        << currentnode->level << " Type : " << currentnode->type << endl;
        found=true;
      }
      if (!found){
        cout << "not found" << endl;
      }
      return;
    }
  }


	void showmenu(){
		cout<<"=================================\n";
		cout<<"Pokemon Rooster Menu\n";
		cout<<"=================================\n";
		cout<<"1.Add a Pokemon\n";
		cout<<"2.Delete a Pokemon\n";
		cout<<"3.Show number of Pokemons in rooster\n";
		cout<<"4.Find Pokemon with lowest level\n";
		cout<<"5.Find Pokemon with highest level\n";
		cout<<"6.Find Pokemon\n";
		cout<<"7.Print all Pokemons\n";
		cout<<"8.Exit\n";
	}

	void select(){
		std::string name, type;
		int pos, ch, level;
		ListElem *temp;
		char yes='y';
		makeEmpty();
		//Make the list empty

		while(yes=='y'){
			cout<<"Enter your choice:";
			cin>>ch;
			switch(ch){
				// Add a new pokemon
				case 1: cout<<"Pokemon name :";
					cin>>name;
					cout<<"Pokemon level :";
					cin>>level;
					cout<<"Pokemon type :";
					cin>>type;
					cout<<"Position into the rooster:";
					cin>>pos;
          Insert(name, level, type, pos, temp);
					break;

				// Delete a pokemon
				case 2:
					cout<<"Position in rooster:";
					cin>>pos;
          Delete(pos, temp);
					break;

				// Show number of Pokemons in rooster
				case 3:
					cout<<"Number of Pokemons:"<< countitem(temp) << endl;
					break;

				// Find Pokemon with lowest level
				case 4:
					//if you found a pokemon
					findmin(temp);
					//else you should return cout<<"Not found\n";
					break;

				// Find Pokemon with highest level
				case 5:
					//if you found a pokemon
					findmax(temp);
					//else you should return cout<<"Not found\n";
					break;

				// Find Pokemon by name and show his informations
				case 6:
					cout<<"Find what:";
					cin>>name;
					//if you found a pokemon :
					find(temp, name);
					//else you should return cout<<"Not found\n";


					break;

				// Show all Pokemon in rooster
				case 7:
					cout<<"All Pokemons in rooster:\n";
          printall(temp);
					break;

				// Quit Pokemon Rooster
				case 8:
					exit(0);
				default: cout<<"Invalid choice\n";
			}
			cout<<"Continue?y/n:";
			cin>>yes;
		}
	}


int main(){
	showmenu();
	select();
	return 0;
}
