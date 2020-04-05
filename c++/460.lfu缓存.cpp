/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU缓存
 * 题解博客：https://blog.csdn.net/feng964497595/article/details/105329149
 */

// @lc code=start
class LFUCache {
public:
    LFUCache(int capacity) : m_dwCapacity(capacity) {
        m_dwCurrent = 0;
        m_dwTime = 0;
    }

    int get(int key) {
        auto mit = m_mIndex.find(key);
        if (m_mIndex.end() == mit)
            return -1;

        // 找到了，更新访问频率和时间
        ++m_dwTime;
        m_setCache.erase(mit->second);
        mit->second.fre++;
        mit->second.time = m_dwTime;
        m_setCache.insert(mit->second);

        return mit->second.value;
    }

    void put(int key, int value) {
        if (0 == m_dwCapacity)
            return;

        ++m_dwTime;
        auto mit = m_mIndex.find(key);
        if (m_mIndex.end() == mit) {
            // key不存在，插入
            if (m_dwCurrent >= m_dwCapacity) {
                // 容量已满，先移除
                m_mIndex.erase(m_setCache.begin()->key);
                m_setCache.erase(m_setCache.begin());
                --m_dwCurrent;
            }

            // 插入数据
            SCacheItem item(1, m_dwTime, key, value);
            m_mIndex.insert(std::make_pair(key, item));
            m_setCache.insert(item);
            ++m_dwCurrent;
        } else {
            // key已存在，更新访问频率、时间和值
            m_setCache.erase(mit->second);
            mit->second.fre++;
            mit->second.time = m_dwTime;
            mit->second.value = value;
            m_setCache.insert(mit->second);
        }
    }

private:
    struct SCacheItem {
        int fre;        // 访问频率
        int time;       // 访问时间
        int key;        // 缓存保留的key
        int value;      // 缓存保留的值

        SCacheItem(int f = 0, int t = 0, int k = -1, int v = -1) : fre(f), time(t), key(k), value(v) {
        }

        bool operator < (const SCacheItem& item) const {
            if (fre == item.fre)
                return time < item.time;
            return fre < item.fre;
        }
    };

private:
    std::unordered_map<int, SCacheItem> m_mIndex;    // 索引
    std::set<SCacheItem> m_setCache;    // 缓存体
    int m_dwCapacity;       // 容量
    int m_dwCurrent;        // 当前数量
    int m_dwTime;           // 充当访问时间
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
