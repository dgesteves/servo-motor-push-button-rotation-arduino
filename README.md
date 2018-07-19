# servo motor push button rotation arduino


first => the digital reading of button state; and the control of a servo motor:
the servo motor turns from zero position to minimum position, then to
maximum, and returns to zero;

//================================================
secund => second (for 10 seconds) the servo motor turns from zero position to minimum position, then
maximum, and returns to zero;
When pressed for 10 seconds, the servo motor will
zero to minimum position, then to maximum, and back to zero

//================================================
third => the servo motor pointer oscillates between the -60 ° and + 60 ° positions; the oscillation period is controlled by
serial port, by sending a digit between '0' (0.5 sec) and '9' (5 sec).
oscillates between the positions -60º and + 60º; the oscillation period is controlled by
serial port, by sending a digit between '0' (0.5 sec) and '9' (5 sec)