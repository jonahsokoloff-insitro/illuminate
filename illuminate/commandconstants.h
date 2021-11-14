/*
  Copyright (c) 2021, Zack Phillips
  Copyright (c) 2018, Zachary Phillips (UC Berkeley)
  All rights reserved.

  BSD 3-Clause License

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
      Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
      Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
      Neither the name of the UC Berkley nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL ZACHARY PHILLIPS (UC BERKELEY) BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA , OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef COMMAND_CONSTANTS_H
#define COMMAND_CONSTANTS_H

// List of command indicies in below array
#define COMMAND_COUNT 69

#define CMD_HELP_IDX 0
#define CMD_ABOUT_IDX 1
#define CMD_REBOOT_IDX 2
#define CMD_SHOW_VERSION 3

#define CMD_AUTOCLEAR_IDX 4
#define CMD_NA_IDX 5
#define CMD_SET_COLOR_IDX 6
#define CMD_SET_BRIGHTNESS 7
#define CMD_SET_ARRAY_DIST 8

#define CMD_LED_IDX 9

#define CMD_CLEAR_IDX 10
#define CMD_FILL_IDX 11
#define CMD_BF_IDX 12
#define CMD_DF_IDX 13
#define CMD_DPC_IDX 14
#define CMD_CDPC_IDX 15
#define CMD_AN_IDX 16
#define CMD_HALF_ANNULUS 17
#define CMD_DQ_IDX 18
#define CMD_CDF_IDX 19
#define CMD_NAV_DPC_IDX 20

#define CMD_SCF_IDX 21
#define CMD_SCB_IDX 22

#define CMD_LEN_SEQ_IDX 23
#define CMD_SET_SEQ_IDX 24
#define CMD_RUN_SEQ_IDX 25
#define CMD_RUN_SEQ_FAST_IDX 26
#define CMD_PRINT_SEQ_IDX 27
#define CMD_PRINT_SEQ_LENGTH_IDX 28
#define CMD_STEP_SEQ_IDX 29
#define CMD_RESET_SEQ_IDX 30
#define CMD_SET_SEQ_BIT_DEPTH 31
#define CMD_SET_SEQ_ZEROS 32

#define CMD_TRIG_IDX 33
#define CMD_TRIG_SETUP_IDX 34
#define CMD_TRIG_TEST_IDX 35
#define CMD_CHANNEL_IDX 36
#define CMD_TOGGLE_DEBUG_IDX 37
#define CMD_PIN_ORDER_IDX 38
#define CMD_DELAY 39
#define CMD_SET_MAX_CURRENT 40
#define CMD_SET_MAX_CURRENT_ENFORCEMENT 41

#define CMD_PRINT_VALS_IDX 42
#define CMD_PRINT_PARAMS 43
#define CMD_PRINT_LED_POSITIONS 44
#define CMD_PRINT_LED_POSITIONS_NA 45

#define CMD_DISCO_IDX 46
#define CMD_DEMO_IDX 47
#define CMD_WATER_IDX 48

#define CMD_SET_PN 49
#define CMD_SET_SN 50

#define CMD_RUN_SEQ_DPC_IDX 51
#define CMD_RUN_SEQ_FPM_IDX 52

#define CMD_SET_BAUD_RATE 53
#define CMD_SET_GSCLK_FREQ 54

#define CMD_SET_HUMAN 55
#define CMD_SET_MACHINE 56

#define CMD_PRINT_SOURCE_VOLTAGE_SENSING 57
#define CMD_TOGGLE_SOURCE_VOLTAGE_SENSING 58
#define CMD_PRINT_POWER_SOURCE_VOLTAGE 59

#define CMD_SET_INNER_NA 60

#define CMD_TRIGGER_INPUT_TIMEOUT 61
#define CMD_TRIGGER_OUTPUT_PULSE_WIDTH 62
#define CMD_TRIGGER_INPUT_POLARITY 63
#define CMD_TRIGGER_OUTPUT_POLARITY 64
#define CMD_TRIGGER_OUTPUT_DELAY 65
#define CMD_TRIGGER_INPUT_PIN 66
#define CMD_TRIGGER_OUTPUT_PIN 67

#define CMD_COSINE_FACTOR 68

// Syntax is: {short command, long command, description, syntax}
const char* command_list[COMMAND_COUNT][4] = {

  // High-level Commands
  {"?", "help", "Display help info", "?"},
  {"info", "about", "Displays information about this LED Array", "about"},
  {"reboot", "reset", "Runs setup routine again, for resetting LED array", "reboot"},
  {"ver", "version", "Display controller version number", "version"},

  // System Parameters
  {"ac", "autoClear", "Toggle clearing of array between led updates. Can call with or without options.", "ac --or-- ac.[0/1]"},
  {"na", "setNa", "Set na used for bf/df/dpc/cdpc patterns", "na.[na*100]"},
  {"sc", "setColor", "Set LED array color", "sc,[rgbVal] --or-- sc.[rVal].[gVal].[bVal]"},
  {"sb", "setBrightness", "Set LED array brightness", "sb,[rgbVal] --or-- sb.[rVal].[gVal].[bVal]"},
  {"sad", "setArrayDistance", "Set LED array distance", "sad,[dist (mm)]"},

  // Single (or multiple) LED Display
  {"l", "led", "Turn on a single LED (or multiple LEDs in a list)", "l.[led #].[led #], ..."},

  // General Display
  {"x", "xx", "Clear the LED array.", "x"},
  {"ff", "fillArray", "Fill the LED array with default color.", "ff"},
  {"bf", "brightfield", "Display brightfield pattern", "bf"},
  {"df", "darkfield", "Display darkfield pattern", "df"},
  {"dpc", "halfCircle", "Illuminate half-circle (DPC) pattern", "dpc.[t/b/l/r] --or-- dpc.[top/bottom/left/right] --or-- dpc (will raw first pattern)"},
  {"cdpc", "colorDpc", "Illuminate color DPC (cDPC) pattern", "cdpc.[rVal],[gVal].[bVal]) --or-- cdpc.[rgbVal]) --or-- cdpc"},
  {"an", "annulus", "Display annulus pattern set by min/max na", "an.[minNA*100].[maxNA*100]"},
  {"ha", "halfAnnulus", "Illuminate half annulus", "ha.[type].[minNA*100].[maxNA*100]"},
  {"dq", "drawQuadrant", "Draws single quadrant", "dq --or-- dq.[rVal].[gVal].[bVal]"},
  {"cdf", "Color Darkfield", "Draws color darkfield pattern", "cdf.[rVal].[gVal].[bVal]) --or-- cdf.[rgbVal]) --or-- cdf"},
  {"ndpc", "navigator", "Illuminate half-circle (DPC) pattern with navigator", "ndpc.[t/b/l/r] --or-- ndpc.[top/bottom/left/right]"},

  // Single LED Scanning
  {"scf", "scanFull", "Scan all active LEDs. Sends trigger pulse in between images. Outputs LED list to serial terminal.", "scf,[delay_ms]"},
  {"scb", "scanBrightfield", "Scan all brightfield LEDs. Sends trigger pulse in between images. Outputs LED list to serial terminal.", "scb,[delay_ms]"},

  // Custom Sequence Scanning
  {"ssl",   "setSeqLength", "Set sequence length in terms of independent patterns", "ssl,[Sequence length]"},
  {"ssv",   "setSeqValue", "Set sequence value", "ssl.[# Number of LEDs], [LED number 0], [LED number 1]], [LED number 2], ..."},
  {"rseq",  "runSequence", "Runs sequence with specified delay between each update. If update speed is too fast, a :( is shown on the LED array.", "rseq,[Delay between each pattern in ms].[number of times to repeat pattern].[trigger output 0 mode].[trigger output 1 mode].[trigger input 0 mode].[trigger input 1 mode]"},
  {"rseqf", "runSequenceFast", "Runs sequence with specified delay between each update. Uses parallel digital IO to acheive very fast speeds (single us). Only available on certain LED arrays.", "rseqf,[Delay between each pattern in ms].[trigger mode for index 0].[trigger mode for index 1].[trigger mode for index 2] "},
  {"pseq",  "printSeq", "Prints sequence values to the terminal", "pseq"}, 
  {"pseql", "printSeqLength", "Prints sequence length to the terminal", "pseql"},
  {"sseq",  "stepSequence", "Runs sequence with specified delay between each update. If update speed is too fast, a :( is shown on the LED array.", "sseq.[trigger output mode for index 0].[trigger output mode for index 1],"},
  {"reseq", "resetSeq", "Resets sequence index to start", "reseq"},
  {"ssbd",  "setSeqBitDepth", "Sets bit depth of sequence values (1, 8, or 16)", "ssbd.1 --or-- ssbd.8 --or-- ssbd.16."},
  {"ssz",   "setSeqZeros", "Sets a range of the sequence entries to zero, starting at the current sequence index", "ssz.10"},

  // Debugging, Low-level Access, etc.
  {"tr", "trig", "Output TTL trigger pulse to camera", "tr.[trigger index]"},
  {"trs", "trigSetup", "Set up hardware (TTL) triggering", "trs.[trigger index].[trigger pin index].['trigger delay between H and L pulses]"},
  {"trt", "trigTest", "Waits for trigger pulses on the defined channel", "trt.[trigger input index]"},
  {"ch", "drawChannel", "Draw LED by hardware channel (use for debugging)", "dc.[led#]"},
  {"dbg", "debug", "Toggle debug flag. Can call with or without options.", "dbg.[command router debug].[LED array (generic) debug].[LED interface debug] --or-- dbg (toggles all between level 1 or 0)"},
  {"spo", "setPinOrder", "Sets pin order (R/G/B) for setup purposes. Also can flip individual leds by passing fourth argument.", "spo.[rChan].[gChan].[bChan] --or-- spo.[led#].[rChan].[gChan].[bChan]"},
  {"delay", "wait", "Simply puts the device in a loop for the amount of time in ms", "delay.[length of time in ms]"},
  {"smc", "setMaxCurrent", "Sets max current in amps", "smc.[current limit in amps]"},
  {"smce", "setMaxCurrentEnforcement", "Sets whether or not max current limit is enforced (0 is no, all other values are yes)", "smce.[0, 1]"},

  // Quering System State
  {"pvals", "printVals", "Print led values for software interface", "pvals"},
  {"pp", "printParams", "Prints system parameters such as NA, LED Array z-distance, etc. in the format of a json file", "pp"},
  {"pledpos", "printLedPositions", "Prints the positions of each LED in cartesian coordinates.", "pledpos"},
  {"pledposna", "printLedPositionsNa", "Prints the positions of each LED in NA coordinates (NA_x, NA_y, NA_distance", "pledposna"},

  // Stored Patterns
  {"disco", "party", "Illuminate a random color pattern of LEDs", "disco.[Number of LEDs in pattern]"},
  {"demo", "runDemo", "Runs a demo routine to show what the array can do.", "demo"},
  {"water", "waterDrop", "Water drop demo", "water"},

  // Set part and serial number in EEPROM
  {"setsn", "setSerialNumber", "Sets device serial number in EEPROM (DO NOT USE UNLESS YOU KNOW WHAT YOU ARE DOING", "setsn"},
  {"setpn", "setPartNumber", "Sets device part number in EEPROM (DO NOT USE UNLESS YOU KNOW WHAT YOU ARE DOING", "setpn"},

  // Run case-specific sequences
  {"rdpc",  "runDpc", "Runs a DPC sequence with specified delay between each update. If update speed is too fast, a warning message will print.", "rdpc,[Delay between each pattern in ms (can be zero)].[Number of acquisitions].[trigger output mode for trigger output 0].[trigger input mode for trigger input 0].[trigger output mode for trigger output 1].[trigger input mode for trigger input 1]"},
  {"rfpm",  "runFpm", "Runs a FPM sequence with specified delay between each update. If update speed is too fast, a warning message will print.", "rfpm,[Delay between each pattern in ms (can be zero)].[Number of acquisitions].[Maximum NA * 100 (e.g. 0.25NA would be 25].[trigger output mode for trigger output 0].[trigger input mode for trigger input 0].[trigger output mode for trigger output 1].[trigger input mode for trigger input 1]"},

  // Functions to set baud rate and gsclk frequency (for TLC5955 based boards)
  {"sbr",  "setBaudRate", "Sets SPI baud rate for TLC5955 Chips in Hz (baud)", "sbr.1000000"},
  {"sgs",  "setGsclkFreq", "Sets GSCLK frequency in Hz", "sgs.1000000"},

  {"human", "setModeHuman", "Sets command mode to human-readable", "human"},
  {"machine", "setModeMachine", "Sets command mode to machine-readable", "machine"},

  {"pwrc", "isPowerSourceConnected", "Gets the state of the power source, if this device has the hardware to do so.", "pwrc"},
  {"pwrs", "togglePowerSourceSensing", "Toggle power source sensing on or off.", "pwrs"},
  {"pwrv", "printPowerSourceVoltage", "Print power sourve voltage.", "pwrv"},

  {"nai", "setInnerNa", "Sets the inner NA. (nai.20 sets an inner NA of 0.20)  Respected by bf, dpc, and rdpc commands. Default is 0", "nai.20"},
  {"trinputtimeout", "triggerInputTimeout", "Sets the trigger input timeout in seconds. Default is 3600", "trinputtimeout.10"},
  {"troutputpulsewidth", "triggerOutputPulseWidth", "Sets the trigger pulse width in microseconds, default is 1000.", "troutputpulsewidth.1000"},
  {"trinputpolarity", "triggerInputPolarity", "Sets the trigger input polarity. 1=active high, 0=active low. Default is 1.", "trinputpolarity.1"},
  {"troutputpolarity", "triggerOutputPolarity", "Sets the trigger output polarity. 1=active high, 0=active low. Default is 1.", "troutputpolarity.1"},
  {"troutputdelay", "triggerOutputDelay", "Sets the trigger delay in microseconds. Default is zero.", "troutputdelay.0"},
  {"trinputpin", "triggerInputPin", "Returns the Teensy pin of the trigger inputsignal. Used only for debugging.", "trinputpin"},
  {"troutputpin", "triggerOutputPin", "Returns the Teensy pin of the trigger outputsignal. Used only for debugging.", "troutputpin"},

  {"cos", "cosineFactor", "Returns or sets the cosine factor, used to scale LED intensity (so outer LEDs are brighter). Input is cos.[integer cosine factor]", "cos.2"}

};

#endif
