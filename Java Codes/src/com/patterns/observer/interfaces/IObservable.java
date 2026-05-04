package com.patterns.observer.interfaces;

public interface IObservable {
    public void addObserver(IObserver observer);
    public void removeObserver(IObserver observer);
    public void triggerNotification();
}
