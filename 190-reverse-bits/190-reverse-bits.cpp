class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t back = 1;
        uint32_t front = 1 << 31;
        for(int i = 0; i < 16;i++){
            bool digita = ((n & back) != 0)?true:false;
            bool digitb = ((n & front) != 0)?true:false;
            if (digita xor digitb){
                // if a swap is needed
                if (digita){
                    n = front | n;
                    n = ~back & n;
                }else{
                    n = back | n;
                    n = ~front & n;
                }
            }
            back = back << 1;
            front = front >> 1;
        }
        return n;
    }
};