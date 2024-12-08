void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

// centre.c
bool check() {
        turn_left();
        turn_left();
        if (beepers_present()) {
            turn_left();
            turn_left();
            if (beepers_present()) {
                turn_left();
                turn_left();
                step();
                turn_left();
                return true;
            }
        }
        else {
            turn_left();
            turn_left();
            return false;
        }
    return false;
}


void find_center(){
    while (not_facing_north()) turn_left();
    while(front_is_clear()) step();
    while (not_facing_west()) turn_left();
    while (front_is_clear()) step();
    while (not_facing_south()) turn_left();
    put_beeper();
    while (front_is_clear()) step();
    turn_left();
    turn_left();
    put_beeper();
    step();
    while (check() == false) {
        while (no_beepers_present() && front_is_clear()) step();
        turn_left();
        turn_left();
        if (beepers_present()) pick_beeper();
        if (front_is_clear()) step();
        if (no_beepers_present()) put_beeper();
        if (front_is_clear()) step();
    }
    turn_left();
    step();
    if (beepers_present()) pick_beeper();
    turn_left();
    turn_left();
    step();
    turn_right();
    while (front_is_clear()) step();
    turn_left();
    turn_left();
    put_beeper();
    step();
    while (check() == false) {
        while (no_beepers_present() && front_is_clear()) step();
        turn_left();
        turn_left();
        if (beepers_present()) pick_beeper();
        if (front_is_clear()) step();
        if (no_beepers_present()) put_beeper();
        if (front_is_clear()) step();
    }
    turn_left();
    step();
    if (beepers_present()) pick_beeper();
    turn_left();
    turn_left();
    step();
    pick_beeper();
    
}

// olympics.c
void olympics() {
    while (no_beepers_present()){ 
        while (front_is_blocked() && not_facing_north()) turn_left();
        if (not_facing_north()){
            while (not_facing_north()) turn_left();
            step();
        }
        else {
            while (right_is_blocked() ) step();
        }
        turn_right();
        if (front_is_clear()){
            step();
        } while (right_is_blocked()){
            step();
        } if (right_is_clear()){
            turn_right();
        } while (front_is_clear()){
            step();
        }
    }
    pick_beeper();
}


void back_going(){
    while (not_facing_north()) turn_left();
    
    while (front_is_clear()) step();
    
    while (!facing_west()) turn_left();
    
    while (front_is_clear()) step();
    
    while (!facing_south()) turn_left();
    
    while (!front_is_blocked()) step();
}


// chessboard.c
bool checking() {
    set_step_delay(0);
    if (facing_west()) {
        turn_right();
        step();
        if (beepers_present()) {
            turn_left();
            turn_left();
            step();
            turn_right();
            set_step_delay(100);
            return 1;
        }
        turn_left();
        turn_left();
        step();
        turn_right(); 
    }
    set_step_delay(100);
    return 0;
}


void chessboard(){
   while(not_facing_west()){
      turn_left();   }
   while(front_is_clear()){
      step();  }
   while(not_facing_north()){
      turn_left();}
   while(front_is_clear()){
      step();}
   while(not_facing_east()) turn_left();
   while (true) {
    if (facing_east()) {
        if (front_is_clear()) step(); 
        put_beeper();
        if (front_is_clear()) step();   
        if (front_is_blocked() && right_is_clear()) {
            turn_right();
            step();
            turn_right();
        }
    }
    else if (facing_west()) {
        if (checking() == 0) {
            if (no_beepers_present()) put_beeper();
        }
        if (front_is_clear()) step();
        if (checking() == 0) {
            if (no_beepers_present()) put_beeper();
        }  
        if (front_is_blocked() && left_is_clear()) {
            turn_left();
            step();
            turn_left();
        }
    }
    if (facing_west() && front_is_blocked() && left_is_blocked()) {
        break;
        return;
    }
    if (facing_east() && front_is_blocked() && right_is_blocked()) {
        break;
        return;
    }
   }
}


// stairs.c
void stairs(){
    while (true) {
        if (front_is_clear() && right_is_blocked()) step();
        else if (right_is_clear()) {
            turn_right();
            if (front_is_clear()) step();
        }
        else if (left_is_clear()) {
            turn_left();
            if (front_is_clear()) step();
        }
        else {
            turn_left();
            turn_left();
        }
        if (beepers_present()) {
            while (beepers_present()) pick_beeper();
        }
        if (facing_east() && left_is_blocked() && right_is_blocked()) {
            break;
        }
    }
    while (beepers_in_bag()) put_beeper();
}


// yolka.c
void yolka() {
    while (true) {
        if (right_is_blocked() && front_is_clear()) step();
        else if (right_is_clear()) {
            turn_right();
            step();
        }
        else {
            turn_left();
            turn_left();
        }
        if (right_is_blocked() && left_is_clear()) put_beeper();
        if (right_is_clear() && facing_east()) {
            break;
        }
    }
    put_beeper();
    put_beeper();
    while (true) {
        if (right_is_blocked() && front_is_clear()) step();
        else if (right_is_clear()) {
            turn_right();
            step();
        }
        else {
            turn_left();
            turn_left();
        }
        if (right_is_blocked() && left_is_clear()) put_beeper();
        if (right_is_blocked() && facing_east() && front_is_blocked()) {
            break;
        }
    }
    pick_beeper();
    while (not_facing_west()) turn_left();
    while (no_beepers_present() && front_is_clear()) step();
    pick_beeper();
    turn_left();
    turn_left();
    while (front_is_clear()) step();
}
