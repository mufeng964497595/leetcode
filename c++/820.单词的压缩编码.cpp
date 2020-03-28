/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105163551
 */

// @lc code=start
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        SuffixTree root;
        for (auto word : words) {
            int len = word.size();
            SuffixTree* pNode = &root;  // 用来遍历的指针
            int layer = 0;
            bool isSuffix = true;   // 标记当前字符串是否是后缀串
            for (int i = len - 1; i >= 0; --i) {
                ++layer;
                auto& next = pNode->next;
                if (next.find(word[i]) != next.end()) {
                    // 使用现有节点
                    pNode = next[word[i]];
                } else {
                    // 创建新节点
                    SuffixTree* pNewNode = new SuffixTree();
                    next.insert(std::make_pair(word[i], pNewNode));
                    pNode = pNewNode;
                    isSuffix = false;
                }

                if (pNode->isEnd && i != 0) {
                    // 当前节点有是某个字符串的终结节点，减去这个字符串的长度
                    // 加上i!=0的判断，是因为i==0这种情况下就意味着有两个字符串完全相同，
                    // 前面的处理逻辑本身就会将后加的字符串当成后缀给舍弃，就没必要减掉前面的字符串。
                    ans -= layer + 1;
                    pNode->isEnd = false;
                }
            }

            if (!isSuffix) {
                ans += layer + 1;  // 加上#号的长度
                pNode->isEnd = true;  // 最后一个节点打上终结标记
            }
        }

        return ans;
    }

private:
    // 后缀树节点
    class SuffixTree {
    public:
        SuffixTree() : isEnd(false) {
        }

        ~SuffixTree() {
            for (auto item : next) {
                Delete(item.second);
            }
        }

    private:
        // 释放内存
        void Delete(SuffixTree* tree) {
            if (!tree) return;
            for (auto item : tree->next) {
                Delete(item.second);
            }
        }

    public:
        std::map<int, SuffixTree*> next;  // 树的子节点
        bool isEnd;  // 字符串终结标记
    };
};
// @lc code=end
