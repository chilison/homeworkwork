//
//  method.cpp
//  hwsem26
//
//  Created by Соня Артеменко on 05.04.2022.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "description.cpp"


void Base::SetHP(int hp) {}
void Base::SetAtk(int atk) {}
void Base::SetDef(int def) {}
void Base::SetLevel(int lvl) {}
Base::Base(std::string Name) : name(Name) {}
Base::~Base() {}
int Base::GetHP() const {return 0;}
int Base::GetAtk() const {return 0;}
int Base::GetDef() const {return 0;}
int Base::GetLevel() const {return 0;}
bool Base::IsDead() const {return true;}
void Base::Victory(Base &other) {}
void Base::Attack(Base &other) {
    if (IsDead()) {
        return;
    }
    int dmg = std::max(1, GetAtk() - other.GetDef());
    other.SetHP(other.GetHP() - dmg);
    std::cout << name << " attacked " << other.name << " and dealt " << dmg << " damage!" << std::endl;
    if (other.IsDead()) {
    std::cout << name << " won!" << std::endl;
    Victory(other); // тут пришлось добавить аргумент, тк иначе я не могу узнать, чьи очки забирать
  }
}
void Base::Load(int hp, int atk, int def, int lvl) {
    SetHP(hp);
    SetAtk(atk);
    SetDef(def);
    SetLevel(lvl);
    std::cout << "hp: " << GetHP() << std::endl;
    std::cout << "atk: " << GetAtk() << std::endl;
    std::cout << "def: " << GetDef() << std::endl;
    std::cout << "lvl: " << GetLevel() << std::endl;
}





Character::Character(std::string Name) : Base(Name) {}
void Victory(Base &other) {}
void Character::SetHP(int hp) {
    _hp = hp;
}
void Character::SetAtk(int atk) {
    _atk = atk;
}
void Character::SetDef(int def) {
    _def = def;
}
void Character::SetLevel(int lvl) {
    if (lvl >= MIN_LEVEL) _lvl = lvl;
}
bool Character::IsDead() {
    if (_hp <= 0) {return true;} else {return false;}
}
int Character::GetHP() {
    return _hp;;
}
int Character::GetAtk() {
    return _def;;
}
int Character::GetDef() {
    return _def;;
}
int Character::GetLevel() {
    return _lvl;
}
Character::~Character() {}




Player::Player(std::string Name) : Character(Name) {}
void Player::Victory(Base &other) {
    _xp += other.GetHP();
    if (_xp >= 100) {
        SetLevel(GetLevel()+1);
    }
}
void Player::SetXP(int xp) {
    _xp = xp;
}
int Player::GetXP() {
    return _xp;
}
Player::~Player() {}




Enemy::Enemy(std::string Name) : Character(Name) {}
void Enemy::Victory(Base &other) {}
/*
void Enemy::SetLevel(int lvl){
    Character::SetLevel(lvl);
}
 */
void Enemy::SetXpReward(int reward) {
    _xpReward = floor(5*GetLevel()+GetDef()/4+GetAtk()/4);
}
int Enemy::GetXpReward() {
    return _xpReward;
}
Enemy::~Enemy() {}




