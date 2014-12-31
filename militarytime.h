void makeTime( struct tm *tm_info );
void findTimeZone( char *offset, char *timezone );
void strToUpper( char *text );

const char *timezones_values[25] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y",
    "Z"
};

const char *timezones_map[25] = {
    "+0100", "+0200", "+0300", "+0400", "+0500", "+0600", "+0700", "+0800", "+0900", "+1000", "+1100", "+1200",
    "-0100", "-0200", "-0300", "-0400", "-0500", "-0600", "-0700", "-0800", "-0900", "-1000", "-1100", "-1200",
    "+0000"
};
