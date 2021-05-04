#include "card.h"
#include <iostream>

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

Effect Card::getEffect() const{
    return effect;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

void Card::setEffect(Effect e){
    effect = e;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2:
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break; 
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}


SpecialCard::SpecialCard(Color c, Effect e) {
    setColor(c);
    setEffect(e);
}

string SpecialCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2:
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break; 
            
            }
        case 3:
            switch(effect){
                case DRAWTWO:
                    return "| Draw  Two |";
                    break; 
                case REVERSE:
                    return "|  Reverse  |";
                    break;
                case SKIP:
                    return "|   Skip    |";
                    break;
                default:
                    return "|           |";
                    break;
            }
            
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool SpecialCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() ||  effect == discard->getEffect()){
        //case statement
        
        return true;
    } else {
        return false;
    }
}

WildCard::WildCard(WildTypes w) {
    setWildType(w);
}

WildTypes WildCard::getWildType() const{
    return WildType;
}

void WildCard::setWildType(WildTypes w){
    WildType = w;
}


string WildCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3:
            switch(WildType){
                case WILD:
                    return "|   Wild    |";
                    break;
                case DRAWFOUR:
                    return "| Draw Four |";
                    break;
                default:
                    return "|           |";
                    break;
            }
            
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}


bool WildCard::play(Card* discard, GameState *gameState) {
    cout << "Please choose a color: \n1. Red\n2. Blue\n3. Green\n4. Yellow"<<endl;
    Color wildColor;
   //cin >> wildColor;
    switch(WildType){
        case WILD:
            setColor(wildColor);
            return true;
            break;
        case DRAWFOUR:
            setColor(wildColor);
            gameState->numCardsToPlay=0;
            gameState->numCardsToDraw=4;
            return true;
            break;
        default:
            return true;
            break;
    }
    
}