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
            switch(effect){
                case DRAWTWO:
                    return true;
                    break; 
                case REVERSE:
				// changes the rotation of game (from CW to CCW or vice versa) 
				    if (gamestate.reverse = true) {
					    gamestate.turnDirection = BACKWARD; 
			    	}
				    else{
					    gamestate.turnDirection  = FORWARD; 
				    }
                    return true;
                    break;
                case SKIP:
                    if (gamestate.SKIP = true){
                        //figuring this one out next (Kathleen)
                    }
                    return true;
                    break;
                case WILD:
                    return true;
                    break;
                case DRAWFOUR:
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
        return true;
    } else {
        return false;
    }
    
WildCard::WildCard(WildTypes w) {
    setWildType(w);
}

WildCard::getWildType() const{
    return wildType;
}

WildCard::setWildType(w){
    wildType = w;
}


string WildCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3:
            switch(wildType){
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

bool WildCard::play(Card* discard, GameState &gameState) {
    switch(wildType){
        case 
    }
    return true;
}