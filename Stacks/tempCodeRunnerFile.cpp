 stack st;
    st.push(4);
    st.push(2);
    st.push(5);
    st.push(1);
    st.push(87);
    st.push(0);

    st.pop();
    cout << st.size() << endl;
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
 

    cout << (st.isEmpty() ? "EMPTY" : "NON-EMPTY");

