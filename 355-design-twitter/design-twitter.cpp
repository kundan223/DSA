class Twitter {
public:
    
    int time;
    
    struct Tweet {
        int id;
        int time;
    };
    
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
    
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq; 
        
        following[userId].insert(userId);
        
        for (int followee : following[userId]) {
            for (auto &tweet : tweets[followee]) {
                pq.push({tweet.time, tweet.id});
            }
        }
        
        vector<int> res;
        
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};