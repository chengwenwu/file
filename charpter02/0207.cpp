class Time{
public:
    Time();//�Թ��캯����������
    set_time();
    get_time();
private:
    int hour,minute,second;
};
Time::Time(){//���幹�캯������Ҫ�������������޶���"::"
    hour=0;
    minute=0;
    second=0;
}
