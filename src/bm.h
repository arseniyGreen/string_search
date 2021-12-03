#include <iostream>
#include <vector>
#include <memory>
#include <string>

class ContextSearching {

public:

    using StringView = std::string_view;

    virtual ~ContextSearching() = default;

    virtual typename StringView::size_type operator() (const StringView& context, const StringView& looking) const = 0;
};

class BoyerMoore : public ContextSearching {

    static constexpr size_t CharSetCount{ 256 };

public:
    virtual typename StringView::size_type operator() (const StringView& context, const StringView& looking) const override {

        if (looking.empty() || context.empty()) {
            return StringView::npos;
        }

        int badCharTable[CharSetCount] = { 0 };

        this->BuildBadCharacterTable(badCharTable, looking);

        const int contextLength = context.length(), lookingLength = looking.length();

        for (int shift{ 0 }; shift <= (contextLength - lookingLength);) {
            int j = lookingLength - 1;
            // Character compare from right to left
            while (j >= 0 && looking[j] == context[shift + j]) {
                --j;
            }

            if (j < 0) {
                // found string, return its position
                return shift;
            }
            else {

                // Detemined how long to shift, the step is as below,
                // 1. get the last mismatching character  => context[shift + j]
                // 2. From bad char table, check its index in looking string => badCharTable[...]
                // 3. Calulate the distance by subtracting current posistion j and index
                shift += std::max(1, j - badCharTable[context[shift + j]]);
            }

        }
        return StringView::npos;
    }

private:

    template<size_t N>
    static void BuildBadCharacterTable(int(&badCharTable)[N], const StringView& looking) {
        auto lookingLength{ looking.length() };
        for (auto& iter : badCharTable) {
            iter = -1;
        }

        for (int i = 0; i < lookingLength; ++i) {
            badCharTable[looking[i]] = i;
        }
    }
};