#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ability;
class Player;
class Heal;

class Ability
{
protected:
    string name;
public:
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()
    {
        return this->name;
    }
    virtual void UseAbility(Player* P) = 0;
};

class Player
{
private:
    int HP;
    int DMG;
    vector<Ability*> abilities;
public:
    Player()
    {
        this->HP = 100;
        this->DMG = 20;
    }
    void AddAbility(Ability* a)
    {
        abilities.push_back(a);
    }
    void UseAbilities()
    {
        cout << "Abilities: " << endl;
        for (int i = 0; i < abilities.size(); i++) {
            cout << i << " - " << abilities[i]->GetName() << endl;
        }
        int x;
        cout << endl;
        cout << "Choose an ability: ( 0 - 5 ) " << endl;
        cin >> x;
        
        if(x == 0){
            abilities[0]->UseAbility(this);
        }
        else if(x == 1){
            abilities[1]->UseAbility(this);
        }
        else if(x == 2){
            abilities[2]->UseAbility(this);
        }
        else if(x == 3){
            abilities[3]->UseAbility(this);
        }
        else if(x == 4){
            abilities[4]->UseAbility(this);
        }
        else if(x == 5){
            abilities[5]->UseAbility(this);
        }
        else{
            cout << "Choose the correct ability!" << endl;
        }
    }
    void SetHP(int hp)
    {
        this->HP = hp;
    }
    void SetDMG(int dmg)
    {
        this->DMG = dmg;
    }
    int GetHP()
    {
        return this->HP;
    }
    int GetDMG()
    {
        return this->DMG;
    }
};

class Heal : public Ability
{
public:
    Heal(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetHP(P->GetHP()+10);
    }
};
class DoubleDMG : public Ability
{
public:
    DoubleDMG(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetDMG(P->GetDMG()*2);
    }
};
class Earthquake : public Ability
{
public:
    Earthquake(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetDMG(P->GetDMG()+30);
    }
};
class CursedBlade : public Ability
{
public:
    CursedBlade(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetDMG(P->GetDMG()+20);
    }
};
class FlameStrike : public Ability
{
public:
    FlameStrike(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetDMG(P->GetDMG()+15);
    }
};
class RegenerationAura : public Ability
{
public:
    RegenerationAura(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetHP(P->GetHP()+20);
    }
};


int main()
{
    Player* P = new Player();
    cout << "Current HP: " << P->GetHP() << endl;
    cout << "Current DMG: " << P->GetDMG() << endl;
    cout << endl;

    P->AddAbility(new Heal("Heal"));
    P->AddAbility(new DoubleDMG("Double Damage"));
    P->AddAbility(new Earthquake("Earthquake"));
    P->AddAbility(new CursedBlade("Cursed Blade"));
    P->AddAbility(new FlameStrike("Flame Strike"));
    P->AddAbility(new RegenerationAura("Regeneration Aura"));
    
    P->UseAbilities();
    cout << P->GetHP() << endl;
    cout << P->GetDMG() << endl;
    
    return 0;
}