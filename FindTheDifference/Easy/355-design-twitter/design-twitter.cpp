class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweet;
    int timer=0;
    unordered_map<int, unordered_set<int>>foll;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       tweet[userId].push_back({timer++,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int>ans;
       vector<pair<int,int>>allTweets;
          for(auto x: tweet[userId]){
            allTweets.push_back(x);
          }

          for(auto x: foll[userId]){
            for(auto i: tweet[x]){ 
            allTweets.push_back(i);
          }}

          sort(allTweets.rbegin(),allTweets.rend());
          for(auto i =0;i< allTweets.size() && i<10;i++){
            ans.push_back(allTweets[i].second);
          }
          return ans;

        
    }
    
    void follow(int followerId, int followeeId) {
        foll[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       foll[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */