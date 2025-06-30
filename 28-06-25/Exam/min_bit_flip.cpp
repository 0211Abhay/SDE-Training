int minBitFlips(int start, int goal) {
        int change_bits = start ^ goal;
        int count = 0;
        while(change_bits){
            change_bits = change_bits & (change_bits - 1);
            count++;
        }
        return count;
    }