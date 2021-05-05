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
    if(color == discard->getColor() || number == discard->getNumber() || NOCOLOR == discard->getColor()){
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
    if(color == discard->getColor() ||  effect == discard->getEffect() || NOCOLOR == discard->getColor()){
            switch(effect){
                case DRAWTWO:
                    gameState.numCardsToDraw = 2;
                    return true;
                    break; 
                case REVERSE:
				// changes the rotation of game (from CW to CCW or vice versa) 
				    if (gameState.turnDirection == FORWARD) {
					    gameState.turnDirection = BACKWARD; 
			    	}
				    else{
					    gameState.turnDirection  = FORWARD; 
				    }
                    return true;
                    break;
                case SKIP:
                //adds one to the turn
                    gameState.numCardsToPlay = 0;
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
            }
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


bool WildCard::play(Card* discard, GameState &gameState) {
    cout << "Please choose a color: \n0. Red\n1. Blue\n2. Green\n3. Yellow"<<endl;
    Color wildColor;
    int playerChoice;
    while(true){
        cin >> playerChoice;
        if(playerChoice<0 || playerChoice > 3){
            cout << "Please choose one of the available options (0. 1. 2. or 3.)."<<endl;
        }else{
            break;
        }    
    }
    
    wildColor=(Color)playerChoice;
    switch(WildType){
        case WILD:
            setColor(wildColor);
            return true;
            break;
        case DRAWFOUR:
            setColor(wildColor);
            gameState.numCardsToPlay = 0;
            gameState.numCardsToDraw=4;
            return true;
            break;
        default:
            return true;
            break;
    }
    
}