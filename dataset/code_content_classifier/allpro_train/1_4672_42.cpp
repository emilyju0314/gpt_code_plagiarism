#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

typedef string::const_iterator state;
class parse_error{};

const int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0},limit=67108864;
int h,w,current_y,current_x,direction,goal_y,goal_x,ans=0,counter=0;
vector<string> a;

bool is_passable(int y,int x){
    return a[y][x]!='#';
}

void program(state&);
void statement(state&);
void if_statement(state&);
void while_statement(state&);
void motion_statement(state&);
bool condition(state&);

void consume(state &begin,char expected){
    if(*begin==expected) ++begin;
    else{
        cerr << "Exptected '" << expected << "' but got '" << *begin << "'" << endl;
        cerr << "Rest string is '";
        while(*begin){
            cerr << *begin;
            ++begin;
        }
        cerr << "'" << endl;
        throw parse_error();
    }
}

void program(state &begin){
    ++counter;
    if(counter>limit) throw parse_error();

    const string prefix(("[{^v<>"));
    while(prefix.find(*begin)!=string::npos){
        statement(begin);
    }
}

void statement(state &begin){
    ++counter;
    if(counter>limit) throw parse_error();

    if(*begin=='['){
        if_statement(begin);
    }else if(*begin=='{'){
        while_statement(begin);
    }else motion_statement(begin);
}

void if_statement(state &begin){
    ++counter;
    if(counter>limit) throw parse_error();

    consume(begin,'[');
    if(condition(begin)){
        program(begin);
        consume(begin,']');
    }else{
        int depth=1;
        for(;;){
            if(*begin=='['){
                consume(begin,'[');
                ++depth;
            }else if(*begin==']'){
                consume(begin,']');
                --depth;
            }else ++begin;
            if(!depth) return;
        }
    }
}

void while_statement(state &begin){
    ++counter;
    if(counter>limit) throw parse_error();

    consume(begin,'{');
    state condition_iterator=begin;
    for(;;){
        if(condition(begin)) program(begin);
        else{
            int depth=1;
            for(;;){
                if(*begin=='{'){
                    consume(begin,'{');
                    ++depth;
                }else if(*begin=='}'){
                    consume(begin,'}');
                    --depth;
                }else ++begin;
                if(!depth) return;
            }
        }
        begin=condition_iterator;
    }
}

void motion_statement(state &begin){
    ++counter;
    if(counter>limit) throw parse_error();

    if(*begin=='^'){
        consume(begin,'^');
        int next_y=current_y+dy[direction],
            next_x=current_x+dx[direction];
        if(is_passable(next_y,next_x)){
            current_y=next_y;
            current_x=next_x;
        }
    }else if(*begin=='v'){
        consume(begin,'v');
        int next_y=current_y-dy[direction],
            next_x=current_x-dx[direction];
            if(is_passable(next_y,next_x)){
                current_y=next_y;
                current_x=next_x;
            }
    }else if(*begin=='<'){
        consume(begin,'<');
        direction=(direction+3)%4;
    }else{
        consume(begin,'>');
        direction=(direction+1)%4;
    }
    ++ans;
    if(current_y==goal_y and current_x==goal_x) throw parse_error();
}

bool condition(state &begin){
    ++counter;
    if(counter>limit) throw parse_error();

    bool not_op=false;
    if(*begin=='~'){
        consume(begin,'~');
        not_op=true;
    }
    bool res=false;
    if(*begin=='N'){
        consume(begin,'N');
        if(direction==0) res=true;
    }else if(*begin=='E'){
        consume(begin,'E');
        if(direction==1) res=true;
    }else if(*begin=='S'){
        consume(begin,'S');
        if(direction==2) res=true;
    }else if(*begin=='W'){
        consume(begin,'W');
        if(direction==3) res=true;
    }else if(*begin=='C'){
        consume(begin,'C');
        if(!is_passable(current_y+dy[direction],current_x+dx[direction])) res=true;
    }else{
        consume(begin,'T');
        res=true;
    }
    if(not_op) return !res;
    else return res;
}


void solve(){
    cin >> h >> w;
    a.resize(h);
    rep(y,0,h){
        cin >> a[y];
        rep(x,0,w){
            if(a[y][x]=='s'){
                current_y=y;
                current_x=x;
            }
            if(a[y][x]=='g'){
                goal_y=y;
                goal_x=x;
            }
        }
    }
    direction=0;

    string s;
    cin >> s;
    try{
        state begin=s.begin();
        program(begin);
    }catch(...){
    }
    if(current_x==goal_x and current_y==goal_y) cout << ans << endl;
    else cout << -1 << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}