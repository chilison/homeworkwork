//
//  description.cpp
//  hwsem26
//
//  Created by Соня Артеменко on 05.04.2022.
//

#include <stdio.h>
#include <string>
#define MIN_LEVEL 1

using namespace std;

class Base {
protected:
    virtual void SetHP(int hp);
    virtual void SetAtk(int atk);
    virtual void SetDef(int def);
    virtual void SetLevel(int lvl);

public:
    const std::string name;
    Base(std::string Name);
    ~Base();
    virtual int GetHP() const;
    virtual int GetAtk() const;
    virtual int GetDef() const;
    virtual int GetLevel() const;
    virtual bool IsDead() const;
    virtual void Victory(Base &other);
    void Attack(Base &other);
    void Load(int hp, int atk, int def, int lvl);
};

class Character : public Base {
    int _hp;
    int _atk;
    int _def;
    int _lvl;
    
public:
    Character(std::string Name);
    ~Character();
    void SetHP(int hp);
    void SetAtk(int atk);
    void SetDef(int def);
    virtual void SetLevel(int lvl);
    virtual void Victory(Base &other);
    bool IsDead();
    int GetHP();
    int GetAtk();
    int GetDef();
    int GetLevel();
};




class Player : public Character {
    int _xp;

public:
    Player(std::string Name = "Player");
    void Victory(Base &other);
    void SetXP(int xp);
    int GetXP();
    ~Player();
};




class Enemy : public Character {
    int _xpReward;

public:
    Enemy(std::string Name = "Enemy");
    void Victory(Base &other);
    //void SetLevel(int lvl);
    void SetXpReward(int reward);
    int GetXpReward();
    ~Enemy();
};
