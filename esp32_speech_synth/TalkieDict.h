#ifndef TALKIEDICT_H
#define TALKIEDICT_H

#include "Vocab_US_Large.h"
#include <Arduino.h>
#include <Talkie.h>
#include <ctype.h>

struct TalkieWord {
  const char *phrase;
  const uint8_t *voiceData;
};

// Auto-generated from Vocab_US_Large.h: one entry per unique phrase.
const TalkieWord talkieDict[] = {
    {"atu", sp5_ATU},
    {"fss", sp5_FSS},
    {"ils", sp5_ILS},
    {"ifr", sp5_IFR},
    {"vfr", sp5_VFR},
    {"vhe", sp5_VHE},
    {"landing gear", sp5_LANDING_GEAR},
    {"level off", sp5_LEVEL_OFF},
    {"undercarriage", sp5_UNDERCARRIAGE},
    {"spoilers", sp5_SPOILERS},
    {"air brakes", sp5_AIR_BRAKES},
    {"aerial", sp5_AERIAL},
    {"engine", sp5_ENGINE},
    {"flame out", sp5_FLAME_OUT},
    {"flak load", sp5_FLAK_LOAD},
    {"inbound", sp5_INBOUND},
    {"ignite", sp5_IGNITE},
    {"no turn", sp5_NO_TURN},
    {"flaps", sp5_FLAPS},
    {"evacuation", sp5_EVACUATION},
    {"doors", sp5_DOORS},
    {"cabin", sp5_CABIN},
    {"arrival", sp5_ARRIVAL},
    {"acknowledge", sp5_ACKNOWLEDGE},
    {"raise", sp5_RAISE},
    {"list", sp5_LIST},
    {"approach", sp5_APPROACH},
    {"departure", sp5_DEPARTURE},
    {"clearance delivery", sp5_CLEARANCE_DELIVERY},
    {"fuel", sp5_FUEL},
    {"idle", sp5_IDLE},
    {"increase", sp5_INCREASE},
    {"up", sp5_UP},
    {"taxi", sp5_TAXI},
    {"as", sp5_AS},
    {"converging", sp5_CONVERGING},
    {"above", sp5_ABOVE},
    {"brake", sp5_BRAKE},
    {"calm", sp5_CALM},
    {"breaking", sp5_BREAKING},
    {"call", sp5_CALL},
    {"crosswind", sp5_CROSSWIND},
    {"crystals", sp5_CRYSTALS},
    {"cylinder", sp5_CYLINDER},
    {"cycle", sp5_CYCLE},
    {"down", sp5_DOWN},
    {"ground", sp5_GROUND},
    {"full", sp5_FULL},
    {"new", sp5_NEW},
    {"leg", sp5_LEG},
    {"maintain", sp5_MAINTAIN},
    {"landing", sp5_LANDING},
    {"lean", sp5_LEAN},
    {"set", sp5_SET},
    {"short", sp5_SHORT},
    {"wake", sp5_WAKE},
    {"adis", sp5_ADIS},
    {"notem", sp5_NOTEM},
    {"rvrs", sp5_RVRS},
    {"squalking", sp5_SQUALKING},
    {"magnetos", sp5_MAGNETOS},
    {"stabiliser", sp5_STABILISER},
    {"pakm", sp5_PAKM},
    {"selcal", sp5_SELCAL},
    {"vortac", sp5_VORTAC},
    {"vor", sp5_VOR},
    {"barker", sp5_BARKER},
    {"heading", sp5_HEADING},
    {"eta", sp5_ETA},
    {"downwind", sp5_DOWNWIND},
    {"ceiling", sp5_CEILING},
    {"midpoint", sp5_MIDPOINT},
    {"signet", sp5_SIGNET},
    {"roll out", sp5_ROLL_OUT},
    {"crocs", sp5_CROCS},
    {"aircraft", sp5_AIRCRAFT},
    {"altimeter", sp5_ALTIMETER},
    {"autopilot", sp5_AUTOPILOT},
    {"localizer", sp5_LOCALIZER},
    {"cowl", sp5_COWL},
    {"inflight", sp5_INFLIGHT},
    {"overspeed", sp5_OVERSPEED},
    {"launch", sp5_LAUNCH},
    {"tower", sp5_TOWER},
    {"flightwatch", sp5_FLIGHTWATCH},
    {"stall", sp5_STALL},
    {"touchdown", sp5_TOUCHDOWN},
    {"squalk", sp5_SQUALK},
    {"elevation", sp5_ELEVATION},
    {"climb", sp5_CLIMB},
    {"bank", sp5_BANK},
    {"accelerated", sp5_ACCELERATED},
    {"trim", sp5_TRIM},
    {"unicom", sp5_UNICOM},
    {"sloke", sp5_SLOKE},
    {"niner", sp5_NINER},
    {"galley", sp5_GALLEY},
    {"freedom", sp5_FREEDOM},
    {"flight", sp5_FLIGHT},
    {"degree", sp5_DEGREE},
    {"airport", sp5_AIRPORT},
    {"airspeed", sp5_AIRSPEED},
    {"clearance", sp5_CLEARANCE},
    {"altitude", sp5_ALTITUDE},
    {"radial", sp5_RADIAL},
    {"remark", sp5_REMARK},
    {"refuelling", sp5_REFUELLING},
    {"outer", sp5_OUTER},
    {"middle", sp5_MIDDLE},
    {"inner", sp5_INNER},
    {"instruments", sp5_INSTRUMENTS},
    {"approaches", sp5_APPROACHES},
    {"gear", sp5_GEAR},
    {"boost", sp5_BOOST},
    {"telephone", sp5_TELEPHONE},
    {"alpha", sp4_ALPHA},
    {"bravo", sp4_BRAVO},
    {"charlie", sp4_CHARLIE},
    {"delta", sp4_DELTA},
    {"echo", sp4_ECHO},
    {"foxtrot", sp4_FOXTROT},
    {"golf", sp4_GOLF},
    {"hotel", sp4_HOTEL},
    {"india", sp4_INDIA},
    {"juliet", sp4_JULIET},
    {"kilo", sp4_KILO},
    {"lima", sp4_LIMA},
    {"mike", sp4_MIKE},
    {"november", sp4_NOVEMBER},
    {"oscar", sp4_OSCAR},
    {"papa", sp4_PAPA},
    {"quebec", sp4_QUEBEC},
    {"romeo", sp4_ROMEO},
    {"sierra", sp4_SIERRA},
    {"tango", sp4_TANGO},
    {"uniform", sp4_UNIFORM},
    {"victor", sp4_VICTOR},
    {"whiskey", sp4_WHISKEY},
    {"xray", sp4_XRAY},
    {"zulu", sp4_ZULU},
    {"affirmative", sp4_AFFIRMATIVE},
    {"negative", sp4_NEGATIVE},
    {"mayday", sp4_MAYDAY},
    {"warning", sp4_WARNING},
    {"icing", sp4_ICING},
    {"danger", sp4_DANGER},
    {"emergency", sp4_EMERGENCY},
    {"roger", sp4_ROGER},
    {"hertz", sp4_HERTZ},
    {"security", sp4_SECURITY},
    {"target", sp4_TARGET},
    {"vectors", sp4_VECTORS},
    {"light", sp4_LIGHT},
    {"front", sp4_FRONT},
    {"way", sp4_WAY},
    {"glide", sp4_GLIDE},
    {"open", sp4_OPEN},
    {"lights", sp4_LIGHTS},
    {"on", sp4_ON},
    {"gundish", sp4_GUNDISH},
    {"r nav", sp4_R_NAV},
    {"select", sp4_SELECT},
    {"filed", sp4_FILED},
    {"mig", sp4_MIG},
    {"alert", sp4_ALERT},
    {"zone", sp4_ZONE},
    {"terminal", sp4_TERMINAL},
    {"radios", sp4_RADIOS},
    {"speed", sp4_SPEED},
    {"knots", sp4_KNOTS},
    {"expect", sp4_EXPECT},
    {"action", sp4_ACTION},
    {"power", sp4_POWER},
    {"gas", sp4_GAS},
    {"information", sp4_INFORMATION},
    {"true", sp4_TRUE},
    {"pressure", sp4_PRESSURE},
    {"check", sp4_CHECK},
    {"decrease", sp4_DECREASE},
    {"advise", sp4_ADVISE},
    {"you", sp4_YOU},
    {"have", sp4_HAVE},
    {"error2", sp4_ERROR2},
    {"all", sp4_ALL},
    {"long", sp4_LONG},
    {"no", sp4_NO},
    {"immediately", sp4_IMMEDIATELY},
    {"final", sp4_FINAL},
    {"please", sp4_PLEASE},
    {"start", sp4_START},
    {"course", sp4_COURSE},
    {"radar", sp4_RADAR},
    {"plan", sp4_PLAN},
    {"windows", sp4_WINDOWS},
    {"watch", sp4_WATCH},
    {"use", sp4_USE},
    {"turn", sp4_TURN},
    {"traffic", sp4_TRAFFIC},
    {"slow", sp4_SLOW},
    {"release", sp4_RELEASE},
    {"key", sp4_KEY},
    {"ignition", sp4_IGNITION},
    {"rain", sp4_RAIN},
    {"repair", sp4_REPAIR},
    {"cancel", sp4_CANCEL},
    {"verify", sp4_VERIFY},
    {"ready", sp4_READY},
    {"use2", sp4_USE2},
    {"out", sp4_OUT},
    {"other", sp4_OTHER},
    {"oil", sp4_OIL},
    {"off", sp4_OFF},
    {"near", sp4_NEAR},
    {"great", sp4_GREAT},
    {"mixture", sp4_MIXTURE},
    {"much", sp4_MUCH},
    {"great2", sp4_GREAT2},
    {"is", sp4_IS},
    {"caution", sp4_CAUTION},
    {"below", sp4_BELOW},
    {"contact", sp4_CONTACT},
    {"and", sp4_AND},
    {"for", sp4_FOR},
    {"sequence", sp4_SEQUENCE},
    {"side", sp4_SIDE},
    {"to", sp4_TO},
    {"rich", sp4_RICH},
    {"pumps", sp4_PUMPS},
    {"level", sp4_LEVEL},
    {"lower", sp4_LOWER},
    {"rear", sp4_REAR},
    {"hold", sp4_HOLD},
    {"left", sp4_LEFT},
    {"right", sp4_RIGHT},
    {"stray", sp4_STRAY},
    {"close", sp4_CLOSE},
    {"evacuate", sp4_EVACUATE},
    {"failure", sp4_FAILURE},
    {"service", sp4_SERVICE},
    {"abort", sp4_ABORT},
    {"idemtify", sp4_IDEMTIFY},
    {"too low", sp4_TOO_LOW},
    {"centre", sp4_CENTRE},
    {"area", sp4_AREA},
    {"base", sp4_BASE},
    {"control", sp4_CONTROL},
    {"measured", sp4_MEASURED},
    {"d", sp4_D},
    {"the", sp4_THE},
    {"vacuum", sp4_VACUUM},
    {"abean", sp4_ABEAN},
    {"zero", sp3_ZERO},
    {"one", sp3_ONE},
    {"two", sp3_TWO},
    {"three", sp3_THREE},
    {"four", sp3_FOUR},
    {"five", sp3_FIVE},
    {"six", sp3_SIX},
    {"seven", sp3_SEVEN},
    {"eight", sp3_EIGHT},
    {"nine", sp3_NINE},
    {"ten", sp3_TEN},
    {"eleven", sp3_ELEVEN},
    {"twelve", sp3_TWELVE},
    {"thirteen", sp3_THIRTEEN},
    {"fourteen", sp3_FOURTEEN},
    {"fifteen", sp3_FIFTEEN},
    {"sixteen", sp3_SIXTEEN},
    {"seventeen", sp3_SEVENTEEN},
    {"eighteen", sp3_EIGHTEEN},
    {"nineteen", sp3_NINETEEN},
    {"twenty", sp3_TWENTY},
    {"thirty", sp3_THIRTY},
    {"fourty", sp3_FOURTY},
    {"fifty", sp3_FIFTY},
    {"sixty", sp3_SIXTY},
    {"seventy", sp3_SEVENTY},
    {"eighty", sp3_EIGHTY},
    {"ninety", sp3_NINETY},
    {"hundred", sp3_HUNDRED},
    {"thousand", sp3_THOUSAND},
    {"million", sp3_MILLION},
    {"path", sp3_PATH},
    {"point", sp3_POINT},
    {"times", sp3_TIMES},
    {"divided", sp3_DIVIDED},
    {"by", sp3_BY},
    {"hours", sp3_HOURS},
    {"plus", sp3_PLUS},
    {"minus", sp3_MINUS},
    {"equals", sp3_EQUALS},
    {"red", sp3_RED},
    {"yellow", sp3_YELLOW},
    {"green", sp3_GREEN},
    {"white", sp3_WHITE},
    {"thee", sp3_THEE},
    {"answer", sp3_ANSWER},
    {"stop", sp3_STOP},
    {"temperature", sp3_TEMPERATURE},
    {"time", sp3_TIME},
    {"a m", sp3_A_M},
    {"p m", sp3_P_M},
    {"oclock", sp3_OCLOCK},
    {"degrees", sp3_DEGREES},
    {"celcius", sp3_CELCIUS},
    {"farenheit", sp3_FARENHEIT},
    {"error", sp3_ERROR},
    {"miles", sp3_MILES},
    {"per", sp3_PER},
    {"hour", sp3_HOUR},
    {"minutes", sp3_MINUTES},
    {"gusting to", sp3_GUSTING_TO},
    {"gust", sp3_GUST},
    {"east", sp3_EAST},
    {"west", sp3_WEST},
    {"south", sp3_SOUTH},
    {"north", sp3_NORTH},
    {"northeast", sp3_NORTHEAST},
    {"northwest", sp3_NORTHWEST},
    {"southeast", sp3_SOUTHEAST},
    {"southwest", sp3_SOUTHWEST},
    {"hail", sp3_HAIL},
    {"tornado", sp3_TORNADO},
    {"wind", sp3_WIND},
    {"weather", sp3_WEATHER},
    {"showers", sp3_SHOWERS},
    {"sleet", sp3_SLEET},
    {"smoke", sp3_SMOKE},
    {"storm", sp3_STORM},
    {"snow", sp3_SNOW},
    {"sand", sp3_SAND},
    {"pellets", sp3_PELLETS},
    {"ice", sp3_ICE},
    {"heat", sp3_HEAT},
    {"fog", sp3_FOG},
    {"heavy", sp3_HEAVY},
    {"land", sp3_LAND},
    {"thin", sp3_THIN},
    {"of", sp3_OF},
    {"obscured", sp3_OBSCURED},
    {"broken", sp3_BROKEN},
    {"aloft", sp3_ALOFT},
    {"partially", sp3_PARTIALLY},
    {"visibility", sp3_VISIBILITY},
    {"drizzle", sp3_DRIZZLE},
    {"indicated", sp3_INDICATED},
    {"severe", sp3_SEVERE},
    {"moderate", sp3_MODERATE},
    {"greenwich", sp3_GREENWICH},
    {"mean", sp3_MEAN},
    {"mist", sp3_MIST},
    {"estimated", sp3_ESTIMATED},
    {"decreasing", sp3_DECREASING},
    {"moving", sp3_MOVING},
    {"alternate", sp3_ALTERNATE},
    {"clear", sp3_CLEAR},
    {"current", sp3_CURRENT},
    {"blowing", sp3_BLOWING},
    {"at", sp3_AT},
    {"turbulance", sp3_TURBULANCE},
    {"thinly", sp3_THINLY},
    {"increasing", sp3_INCREASING},
    {"more than", sp3_MORE_THAN},
    {"less than", sp3_LESS_THAN},
    {"freezing", sp3_FREEZING},
    {"air", sp3_AIR},
    {"haze", sp3_HAZE},
    {"high", sp3_HIGH},
    {"scattered", sp3_SCATTERED},
    {"increasing to", sp3_INCREASING_TO},
    {"in", sp3_IN},
    {"low", sp3_LOW},
    {"thunderstorm", sp3_THUNDERSTORM},
    {"overcast", sp3_OVERCAST},
    {"unlimited", sp3_UNLIMITED},
    {"low2", sp3_LOW2},
    {"percent", sp3_PERCENT},
    {"over", sp3_OVER},
    {"thir ", sp2_THIR_},
    {"fif ", sp2_FIF_},
    {" teen", sp2__TEEN},
    {"a", sp2_A},
    {"b", sp2_B},
    {"c", sp2_C},
    {"e", sp2_E},
    {"f", sp2_F},
    {"g", sp2_G},
    {"h", sp2_H},
    {"i", sp2_I},
    {"l", sp2_L},
    {"j", sp2_J},
    {"k", sp2_K},
    {"m", sp2_M},
    {"n", sp2_N},
    {"o", sp2_O},
    {"p", sp2_P},
    {"q", sp2_Q},
    {"r", sp2_R},
    {"s", sp2_S},
    {"t", sp2_T},
    {"u", sp2_U},
    {"v", sp2_V},
    {"w", sp2_W},
    {"x", sp2_X},
    {"y", sp2_Y},
    {"z", sp2_Z},
    {"henry", sp2_HENRY},
    {"whisky", sp2_WHISKY},
    {"yankee", sp2_YANKEE},
    {"watts", sp2_WATTS},
    {"meter", sp2_METER},
    {"change", sp2_CHANGE},
    {"not", sp2_NOT},
    {"line", sp2_LINE},
    {"automatic", sp2_AUTOMATIC},
    {"weight", sp2_WEIGHT},
    {"display", sp2_DISPLAY},
    {"equal", sp2_EQUAL},
    {"fast", sp2_FAST},
    {"about", sp2_ABOUT},
    {"go", sp2_GO},
    {"inch", sp2_INCH},
    {"motor", sp2_MOTOR},
    {"probe", sp2_PROBE},
    {"under", sp2_UNDER},
    {"operator", sp2_OPERATOR},
    {"amps", sp2_AMPS},
    {"mega", sp2_MEGA},
    {"pico", sp2_PICO},
    {"fire", sp2_FIRE},
    {"complete", sp2_COMPLETE},
    {"machine", sp2_MACHINE},
    {"electrician", sp2_ELECTRICIAN},
    {"phase", sp2_PHASE},
    {"nor", sp2_NOR},
    {"exit", sp2_EXIT},
    {"flow", sp2_FLOW},
    {"gauge", sp2_GAUGE},
    {"inspector", sp2_INSPECTOR},
    {"manual", sp2_MANUAL},
    {"move", sp2_MOVE},
    {"pull", sp2_PULL},
    {"repeat", sp2_REPEAT},
    {"shut", sp2_SHUT},
    {"test", sp2_TEST},
    {"volts", sp2_VOLTS},
    {"gallons", sp2_GALLONS},
    {"micro", sp2_MICRO},
    {"ohms", sp2_OHMS},
    {"circuit", sp2_CIRCUIT},
    {"connect", sp2_CONNECT},
    {"seconds", sp2_SECONDS},
    {"unit", sp2_UNIT},
    {"timer", sp2_TIMER},
    {"adjust", sp2_ADJUST},
    {"between", sp2_BETWEEN},
    {"button", sp2_BUTTON},
    {"clock", sp2_CLOCK},
    {"device", sp2_DEVICE},
    {"fail", sp2_FAIL},
    {"frequency", sp2_FREQUENCY},
    {"gate", sp2_GATE},
    {"intruder", sp2_INTRUDER},
    {"measure", sp2_MEASURE},
    {"pass", sp2_PASS},
    {"position", sp2_POSITION},
    {"push", sp2_PUSH},
    {"tool", sp2_TOOL},
    {"farad", sp2_FARAD},
    {"milli", sp2_MILLI},
    {"switch", sp2_SWITCH},
    {"valve", sp2_VALVE},
    {"val", sp2_VAL},
    {"number", sp2_NUMBER},
    {"break", sp2_BREAK},
    {"calibrate", sp2_CALIBRATE},
    {"crane", sp2_CRANE},
    {"direction", sp2_DIRECTION},
    {"enter", sp2_ENTER},
    {"feet", sp2_FEET},
    {"from", sp2_FROM},
    {"gap", sp2_GAP},
    {"mill", sp2_MILL},
    {"uh", sp2_UH},
    {"past", sp2_PAST},
    {"press", sp2_PRESS},
    {"range", sp2_RANGE},
    {"safe", sp2_SAFE},
};

const int talkieDictSize = sizeof(talkieDict) / sizeof(talkieDict[0]);

const uint8_t *findPhraseSound(const String &phrase) {
  for (int i = 0; i < talkieDictSize; i++) {
    if (phrase.equalsIgnoreCase(talkieDict[i].phrase)) {
      return talkieDict[i].voiceData;
    }
  }
  return nullptr;
}

const uint8_t *getLetterSound(char c) {
  switch (tolower(static_cast<unsigned char>(c))) {
  case 'a':
    return sp2_A;
  case 'b':
    return sp2_B;
  case 'c':
    return sp2_C;
  case 'd':
    return sp2_D;
  case 'e':
    return sp2_E;
  case 'f':
    return sp2_F;
  case 'g':
    return sp2_G;
  case 'h':
    return sp2_H;
  case 'i':
    return sp2_I;
  case 'j':
    return sp2_J;
  case 'k':
    return sp2_K;
  case 'l':
    return sp2_L;
  case 'm':
    return sp2_M;
  case 'n':
    return sp2_N;
  case 'o':
    return sp2_O;
  case 'p':
    return sp2_P;
  case 'q':
    return sp2_Q;
  case 'r':
    return sp2_R;
  case 's':
    return sp2_S;
  case 't':
    return sp2_T;
  case 'u':
    return sp2_U;
  case 'v':
    return sp2_V;
  case 'w':
    return sp2_W;
  case 'x':
    return sp2_X;
  case 'y':
    return sp2_Y;
  case 'z':
    return sp2_Z;
  case '0':
    return sp3_ZERO;
  case '1':
    return sp3_ONE;
  case '2':
    return sp3_TWO;
  case '3':
    return sp3_THREE;
  case '4':
    return sp3_FOUR;
  case '5':
    return sp3_FIVE;
  case '6':
    return sp3_SIX;
  case '7':
    return sp3_SEVEN;
  case '8':
    return sp3_EIGHT;
  case '9':
    return sp3_NINE;
  default:
    return nullptr;
  }
}

void speakWord(Talkie &voice, const String &word) {
  const uint8_t *ptr = findPhraseSound(word);
  if (ptr != nullptr) {
    voice.say(ptr);
    return;
  }

  Serial.print("  -> Word not in dictionary. Spelling it out: ");
  for (int i = 0; i < word.length(); i++) {
    const uint8_t *letterPtr = getLetterSound(word[i]);
    if (letterPtr != nullptr) {
      Serial.print(word[i]);
      voice.say(letterPtr);
      delay(20);
    }
  }
  Serial.println();
}

#endif
