/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 //http://www.cnblogs.com/xinsheng/p/3515119.html
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> record;
        if(node == NULL)
            return node;
 
        deque<UndirectedGraphNode*> queue;
        queue.push_back(node);
 
        while(!queue.empty()) {
            UndirectedGraphNode *nextNode = queue.front();
            queue.pop_front();
 
            if(!record.count(nextNode)) {
                UndirectedGraphNode *newNode = new UndirectedGraphNode(nextNode->label);
                record[nextNode] = newNode;
            }
            for(int i = nextNode->neighbors.size()-1; i >= 0 ; i --) {
                UndirectedGraphNode *childNode = nextNode->neighbors[i];
                if(!record.count(childNode)) {
                    UndirectedGraphNode *newNode = new UndirectedGraphNode(childNode->label);
                    record[childNode] = newNode;
                    queue.push_back(childNode);
                }
                record[nextNode]->neighbors.push_back(record[childNode]);
            }
        }
        return record[node];
    }
};
