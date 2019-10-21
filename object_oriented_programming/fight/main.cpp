#include<iostream>
#include<ctime>

class Warrior{
private:
  std::string name;
  int health;
  int attackPower;
  int blockPower;
public:
  Warrior();
  Warrior(std::string name, int health, int attackPower, int blockPower);
  int attack();
  int block();
  void print();
  int getHealth(){
    return health;
  };
  void decreaseHealth(int value){
    (this -> health - value > 0)? this -> health -= value : this -> health = 0;
  };
  std::string getName(){
    return this -> name;
  }
};

Warrior::Warrior(){
  this -> name = "";
  this -> health = 0;
  this -> attackPower = 0;
  this -> blockPower = 0;
};

Warrior::Warrior(std::string name, int health, int attackPower, int blockPower){
  this -> name = name;
  this -> health = health;
  this -> attackPower = attackPower;
  this -> blockPower = blockPower;
};

int Warrior::attack(){
  if (this -> attackPower > 0){
    int value = std::rand() % this -> attackPower;
    std::cout << this -> name << " attacks with " << value << " power\n";
    return value;
  }
  return 0;
}

int Warrior::block(){
  if (this -> blockPower > 0){
    int value = std::rand() % this -> blockPower;
    std::cout << this -> name << " blocks with " << value << " power\n";
    return value;
  }
  return 0;
}

void Warrior::print(){
  std::cout << this -> name << " - Health: " << this -> health << ", Attack power: " << this -> attackPower << ", Block power: " << this -> blockPower << "\n";
}

class SuperHero: public Warrior{
public:
  SuperHero(): Warrior(){};
  SuperHero(std::string name, int health, int attackPower, int blockPower):
    Warrior(name, health, attackPower, blockPower){};
};

class Vilan: public Warrior{
public:
  Vilan(): Warrior(){};
  Vilan(std::string name, int health, int attackPower, int blockPower):
    Warrior(name, health, attackPower, blockPower){};
};

class Battle{
private:
  SuperHero hero;
  Vilan vilan;
public:
  Battle(SuperHero hero, Vilan vilan);
  void startFight();
};

Battle::Battle(SuperHero hero, Vilan vilan){
  this -> hero = hero;
  this -> vilan = vilan;
  std::cout << "A duel as been set between our beloved " << hero.getName() << " and the bastard " << vilan.getName() << "\n";
}

void Battle::startFight(){
  std::cout << "Let the duel begins...\n";
  while (hero.getHealth() > 0 && vilan.getHealth() > 0){
    int heroIsAttacking = std::rand() % 2;
    if (heroIsAttacking){
      int a = hero.attack();
      int b = vilan.block();
      if (a > b) {vilan.decreaseHealth(a-b);};
    } else {
      int a = vilan.attack();
      int b = hero.block();
      if (a > b) {hero.decreaseHealth(a-b);};
    }
    std::cout << hero.getName() << "'s health: " << hero.getHealth() << " and ";
    std::cout << vilan.getName() << "'s health: " << vilan.getHealth() << "\n";
  }
  if (hero.getHealth() > 0){
    std::cout << "Our beloved " << this -> hero.getName() << " won!\n";
  } else {
    std::cout << "That bastard " << this -> vilan.getName() << " won!\n";
  }
}

int main(){
  std::srand(time(nullptr));
  SuperHero bat("Batman", 100, 30, 20);
  Vilan jocker("Jocker", 100, 30, 20);
  bat.print();
  jocker.print();
  Battle bigOne(bat,jocker);
  bigOne.startFight();
  return 0;
}
