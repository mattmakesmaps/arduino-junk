// bread_blinker.ino

const int LED = 13;
const int BUTTON = 7;

int cur_switch_state = 0; // Current state of the button
int old_switch_state = 0; // Previous state of the button
int light_state = 1; // State of the light

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
}

void loop() {
    cur_switch_state = digitalRead(BUTTON);

    // Appears that HIGH/LOW can be interchanged with 1/0
    // if switch is on, and used to be off, flip the light_state bit.
    if((cur_switch_state == 1) && (old_switch_state == 0)){
        light_state = 1 - light_state;
        delay(250); // required due to switch 'bouncing'
    }

    old_switch_state = cur_switch_state; // store current state of the button.

    if (light_state == 1){
        digitalWrite(LED, 1);
    } else {
        digitalWrite(LED, 0);
    }
}

