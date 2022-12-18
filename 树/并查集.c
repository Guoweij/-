#define SIZE 13
int UFSets[SIZE];//集合元素数组

//初始化并查集
void Intaial(int S[]){
    for (int i = 0; i < SIZE; i++)
    {
        S[i]=-1; //将数组的值赋值-1，表示每个元素都是一个独立的子集
    }
    
}

//查 操作，找到x所属的集合（返回x的根结点）
int Find (int S[],int x){
    while (S[x]>=0)  //循环找到x的根
    {
        x=S[x];  //根的S[]小于0
    }
    return x;
}

//并 操作，将两个集合合并为一个
void Union1 (int S[],int Root1, int Root2){
    //要求Root1和Root2是两个不同的集合
    if (Root1==Root2)//如果相同直接返回
    {
        return;
    }
    else{
        S[Root2]=Root1;  //将元素的下标改为对应的值，从而让root2的根指向root1
    }
    
}

//并操作的优化,让小树合并到大树
void Union2 (int S[],int Root1,int Root2){
    if (Root1==Root2)
    {
        return;
    }
    if (S[Root1]>S[Root2]) //Root2的结点树更少
    {
       S[Root1] +=S[Root2];//累加结点数
       S[Root2]=Root1;//小树合并到大树
    }
    else{
        S[Root2]+=S[Root1];//累加结点数
        S[Root1]=Root2;//小树合并到大树
    }
    
}


//Find操作的优化（压缩路径）
//先找到根结点，再进行“路径压缩”
int Find(int S[],int x){   
    int root = x;
    while (S[root]>=0){
        root =S[root]; //循环找到根结点
    }
    while (x!=root) //压缩路径
    {
        int t=S[x];  //t指向x的父节点
        S[x]=root;   //x直接挂到根节点下
        x=t;
    }
    return root;  //返回根节点编号

}
