package com.patterns.observer;

import com.patterns.observer.interfaces.*;
import com.patterns.observer.impl.*;

public class Client {

    public static void main(String[] args) {
        IObservable observable = new ConcreteObservable();
        IObserver rohan = new ConcreteObserver("Rohan", (ConcreteObservable) observable);
        IObserver rahul = new ConcreteObserver("Rahul", (ConcreteObservable) observable);
        observable.addObserver(rohan);
        observable.addObserver(rahul);
        observable.triggerNotification();
        observable.removeObserver(rahul);
        observable.triggerNotification();

    }
}
