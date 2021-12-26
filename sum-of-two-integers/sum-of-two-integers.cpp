class Solution {
public:
    int getSum(short a, unsigned short b) {
        // im actually stupid lol
        // we consider each inidivdual bit first. if 1 1 or 0 0 then 0. basically xor.
        // for the bit after a 1 1, uiut should be a 1 again. 
        // so xor the 22things, and take the and and shift that to the left one, repeat.
        
        // cool note, left shifting a negative number is undefined. Thus the second param of getSum
        // could output errors. 2 options. mask the MSB or store to an unsigned tmp first before working with the num.  or just change b to unsigned short lol
        if (b == 0) return a;
        return getSum(a ^ b, ((a & b))<<1);
    }
};