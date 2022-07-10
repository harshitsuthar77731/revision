class MedianFinder {
public:
    priority_queue<int>pqasc;
    priority_queue<int,vector<int>,greater<int>>pqdesc;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pqasc.size()==pqdesc.size()){
            if(pqasc.size()==0)
                pqasc.push(num);
            else{
                if(num<=pqasc.top())
                    pqasc.push(num);
                else
                    pqdesc.push(num);
            }
            
        }
        else if(pqasc.size()>pqdesc.size()){
            if(num>=pqasc.top()){
                pqdesc.push(num);
            }
            else{
                int temp = pqasc.top();
                pqasc.pop();
                pqasc.push(num);
                pqdesc.push(temp);
            }
            
        }
        else if(pqasc.size()<pqdesc.size()){
              if(num<=pqdesc.top()){
                pqasc.push(num);
            }
            else{
                int temp = pqdesc.top();
                pqdesc.pop();
                pqdesc.push(num);
                pqasc.push(temp);
            }
        }
    }
    
    double findMedian() {
        if(pqasc.size()>pqdesc.size())
            return pqasc.top();
        else if(pqasc.size()<pqdesc.size())
            return pqdesc.top();
        else
            return ((double)pqasc.top()+(double)pqdesc.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
