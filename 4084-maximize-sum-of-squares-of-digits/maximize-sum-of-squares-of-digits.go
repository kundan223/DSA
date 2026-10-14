
import "strings"

func maxSumOfSquares(num int, sum int) string {
    if sum > 9*num {
        return ""
    }

    var ans strings.Builder
    ans.Grow(num)

    for i := 0; i < num; i++ {
        digit := min(sum, 9)
        ans.WriteByte(byte('0' + digit))
        sum -= digit
    }

    return ans.String()
}
