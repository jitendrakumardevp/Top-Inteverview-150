/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int carry = 1; 
    int temp = 0; 
    int i = 0;
    int *result = (int *)malloc(sizeof(int) * (digitsSize+1));
    int j = digitsSize +1; 
    for(i = digitsSize; i > 0 ; i--)
    {
        temp = digits[i -1] + carry;
        int newDigit = temp % 10; 
        carry = temp / 10; 
        result[i] = newDigit; 
    }

    if(carry && i == 0)
    {
        result[0] = 1; 
        *returnSize =  digitsSize +1;
    }
    else 
    {
        *returnSize = digitsSize;
        return result+1;
    }

   
    return result;

}
