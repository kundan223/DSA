
class ProductOfNumbers {
public:
    vector<int> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {

        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else { 
            int lastProduct = prefix.back();
            int newProduct = lastProduct * num;

            prefix.push_back(newProduct);
        }
    }

    int getProduct(int k) {

        if (k >= prefix.size()) {
            return 0;
        }

        int totalProduct = prefix.back();

        int previousProduct = prefix[prefix.size() - 1 - k];

        return totalProduct / previousProduct;
    }
};
