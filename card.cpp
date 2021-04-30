#include "card.h"

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

NumberCard::NumberCard(Color c, int n, Effect e) {
    setColor(c);
    setNumber(n);
    setEffect(e);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2:
            if(effect == WILD || effect == DRAWFOUR){
                return "|           |";
                break;
            }else{
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
            }
        case 3:
            switch(effect){
            case NUMBER:
                ss << "|     " <<  number << "     |";
                return ss.str();
                break;
            case DRAWTWO:
                return "| Draw  Two |";
                break; 
            case REVERSE:
                return "|  Reverse  |";
                break;
            case SKIP:
                return "|   Skip    |";
                break;
            case WILD:
                return "|   Wild    |";
                break;
            case DRAWFOUR:
                return "| Draw Four |";
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

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber() || effect == WILD || effect == DRAWFOUR){
        return true;
    } else {
        return false;
    }
}