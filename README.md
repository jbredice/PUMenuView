## PUMenuView
PUMenuView is a "tumblr" style popping menu view. It is built with Objective C and fully backed by Auto Layout. With PUMenuView, you can animate the menu easily and add as many menu items as you wish.

####Using with CocoaPods

`pod 'PUMenuView', '~> 1.0.0-beta'`

####DataSource Methods

#####Necessary:
```objc
-(NSInteger)numberOfItemsInMenuView:(PUMenuView *)menuView;
```
This method is necessary because it feeds the view how many menu items it need to display. Since it is must-have info for the menu to layout its subview, it must be implemented by the datasource instance.

#####Optional:
```objc
-(UIButton *)menuView:(PUMenuView *)menuView buttonForItemAtIndex:(NSInteger)index;
```

This method provides the menu the buttons it needs to show. These buttons will serve as the menu items inside the menu. After the buttons are passed in, the menu view will index them and assign the index to their tags. When the buttons are clicked, the delegate method `- (void)menuView:(PUMenuView *) menuView itemDidSelectAtIndex:(NSInteger)index;` will be called.

==================

```objc
-(UIView *)menuView:(PUMenuView *)menuView viewForItemAtIndex:(NSInteger)index;
```

This method provides the menu the customized views it needs to show. This method has a lower priority than `-(UIButton *)menuView:(PUMenuView *)menuView buttonForItemAtIndex:(NSInteger)index;`, which means when `buttonForItemAtIndex` is implemented in the datasource, this method won't be called. Another difference is these customized views has no related delegate methods to detect user interaction. 


####Delegate Methods

####Parameters
