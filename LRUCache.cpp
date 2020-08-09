#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
      int capacity;
      list<pair<int,int>> cache;    //key-value pair
      unordered_map<int, list<pair<int,int>>::iterator> cacheMap;   //key-address map

      void resetPosition(int key, int val)  //to send the latest item to beginning
      {
          cache.erase(cacheMap[key]);
          cache.push_front({key,val});
          cacheMap[key] = cache.begin();
      }

    public:

      LRUCache(int capacity)   //initializing the cache capacity
      {
          this->capacity = capacity;
      }

      /*to check if the key is present in cache and bring
      it to its correct postion*/
      int get(int key)
      {
          if(cacheMap.find(key)!=cacheMap.end())
          {
              resetPosition(key,(*cacheMap[key]).second);
              return (*cacheMap[key]).second;
          }

          return -1;
      }

      //to enter the key value pair in the cache//
      void put(int key, int val)
      {
          if(cacheMap.find(key)!=cacheMap.end())
              resetPosition(key,val);
          else
          {
              cache.push_front({key,val});
              cacheMap[key] = cache.begin();

              if(cacheMap.size()>capacity)
              {
                  cacheMap.erase(cache.back().first);
                  cache.pop_back();
              }
          }
      }

      //To print the cache//
      void printCache()
      {
          cout<<"\nMRU key"<<endl;
          for(auto it=cache.begin();it!=cache.end();it++)
              cout<<"Key: "<<(*it).first<<" "<<"Value: "<<(*it).second<<"\n";
          cout<<"LRU Key"<<endl;
      }
};

int main()
{
    int capacity;
    cout<<"Enter the capacity of the cache: ";
    cin>>capacity;

    LRUCache C(capacity);

    cout<<"Press 1: to put/get a key value pair"<<endl;
    cout<<"Press 2: to print the cache"<<endl;
    cout<<"Press 0: to exit"<<endl;

    int choice;

    do {
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            int key,val;
            cout<<"\nEnter key: ";
            cin>>key;

            if(C.get(key)!=-1)
                cout<<"\nHit !!!";

            else
            {
                cout<<"\nMiss !!!";
                cout<<"\nEnter value: ";
                cin>>val;
                C.put(key,val);
            }

        }

        else if(choice==2)
            C.printCache();

        else if(choice==0)
            break;

        else
            cout<<"\nGive proper choice !!!";

    } while(choice!=0);

    return 0;
}
