#include<iostream>
#include<string.h>

// this is how we include a class
// #include"Hero.cpp"


using namespace std;

class Hero{

    // BY DEFAULT CLASS IS PRIVATE
    // properties
    private:
   
    int health;

    public:
    char *name;
    char level;
   static int timetocom;


    // default constructor
    Hero(){
        cout<<"constructor called"<<endl;
        name = new char[100];
    }



    // parameter constructor
    Hero(int health){
        // this pointer stores address of current obj
        // cout<<this<<endl;
       this->health = health;
    }
    Hero(int health , char level){
        // this pointer stores address of current obj
        // cout<<this<<endl;
       this->health = health;
       this->level = level;
    }
    // copy constructor
    // we have to use pass by ref
    // deep copy

    Hero(Hero& temp){
        char *ch= new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this->name = ch;
        
        this->health = temp.health;
        this->level = temp.level;
    }




// private can only be accesed in classs
// for accessing private members we use function calls
    void print(){
      
        cout<<"name "<<name<<endl;
        cout<<"level "<<this->level<<endl;
        cout<<"health "<<this->health<<endl;
    }
    int getHealth(){
        // health =24;
        return health;
    }
    char getlevel(){
        return level;
    }
    void setHealth(int h ){
        health= h ;
    }
    void setlevel(char l){
        level = l;
    }

    void setName(char name[]){
        //to use strcpy we use string.h
        strcpy(this->name, name);
    }
    // only static member can acc statci fns 
    static int random(){
        return timetocom;
    }


// DESTRUCtoR us e ~ sign 
~Hero(){
    cout<<" destcr "<<endl;
}

};
// intialise static
int Hero::timetocom = 5;


int main(){

    // we dont need object for static data member

    cout<<Hero::timetocom<<endl;
    cout<<Hero::random()<<endl;

    // Hero a;
    // cout<<a.timetocom<<endl;

    // Hero b; 
    // b.timetocom = 10;
    //  cout<<a.timetocom<<endl;
    //  cout<<b.timetocom<<endl;












    // destructor 
    // static
    // Hero a;
    // // static use auto destructor 
    // // dynamic 
    // Hero * b = new Hero;
    // // manually call;
    // delete b;











    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setlevel('D');
    // char name[6]= "rajat";
    // hero1.setName(name);
    // hero1.print();

    // use default copy

    // Hero h2(hero1);
    // // Hero h2 = hero1;
    // // h2.print();

    // hero1.name[0] = 'G';
    // hero1.print();
    // h2.print();


    // hero1 = h2 ; 
    // hero1.print();
    // h2.print();
    
    // object paul
    // Hero paul;
    // cout<<sizeof(paul)<<endl;
    // cout<<"health is "<< paul.getHealth() << endl;
    // // using setter for private 
    // paul.setHealth(23);
    // cout<<"health is "<< paul.getHealth() << endl;
    // // paul.health = 23;
    // // paul.health ;
    // // cout<<" with decalre health is garbage "<<paul.health;
    
    // paul.print();


// staticaly
// Hero b;
// cout<<b.level;
// cout<<b.getHealth()<<endl;
//     // dynamically 
//     // int*i= new int;
//     Hero*a = new Hero;
// a->setHealth(23);
// a->setlevel('B');
     
// cout<<(*a).level;
// cout<<(*a).getHealth()<<endl;
// // arrow is used in dynamic
// cout<<a->level;
// cout<<a->getHealth()<<endl;


    // BTS
    // ramu.Hero() -> constructor default
    // Hero ramu(10);
   
    // cout<<&ramu<<endl;
    // ramu.print();

    // //dynamic
    // Hero *h = new Hero; //same constructor called
    // h->print();


    // Hero temp(22, 'V');
    // temp.print();



    // Hero suresh;
    // suresh.setHealth(70);
    // suresh.setlevel('c');

    // Hero suresh(70 , 'C');
    // suresh.print();


    // // copy constructor

    // Hero Ritesh(suresh);
    // // Ritesh.health = suresh.heath;
    // // Ritesh.level = suresh.level;
    // Ritesh.print();
    




    return 0;
}