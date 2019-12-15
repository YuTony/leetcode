//https://leetcode.com/problems/design-twitter/

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
    struct Tweet {
        int time;
        int id;
        Tweet(int time, int id) {
            this->time = time;
            this->id = id;
        }
    };

   public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time--, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (Tweet& t : tweets[userId]) {
            pq.push({t.time, t.id});
            if (pq.size() > 10) pq.pop();
        }
        for (int user : followees[userId]) {
            for (Tweet& t : tweets[user]) {
                pq.push({t.time, t.id});
                if (pq.size() > 10) pq.pop();
            }
        }
        int n = pq.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }

   private:
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> followees;
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    Twitter twitter = Twitter();

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    auto ans = twitter.getNewsFeed(1);

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    twitter.getNewsFeed(1);

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    twitter.getNewsFeed(1);
}