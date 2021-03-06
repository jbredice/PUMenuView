//
//  PUMenuView.h
//  PUMenuViewDemo
//
//  Created by Wang, Jinghan on 11/06/15.
//  Copyright (c) 2015 Wang, Jinghan. All rights reserved.
//

#import "PUMenuItem.h"

typedef enum {
    AnimationDirectionEnterTopExitTop,
    AnimationDirectionEnterTopExitBottom,
    AnimationDirectionEnterBottomExitTop,
    AnimationDirectionEnterBottomExitBottom
} AnimationDirection;

@class PUMenuView;

@protocol PUMenuViewDataSource

- (NSInteger)numberOfItemsInMenuView:(PUMenuView *)menuView;

@optional
- (UIButton *)menuView:(PUMenuView *)menuView buttonForItemAtIndex:(NSInteger)index;

//This method will not be called if 'menuView:buttonForItemAtIndex:' is implemented in datasource
- (UIView *)menuView:(PUMenuView *)menuView viewForItemAtIndex:(NSInteger)index;

@end


@protocol PUMenuViewDelegate

@optional

- (void)menuView:(PUMenuView *) menuView itemDidSelectAtIndex:(NSInteger)index;
- (void)menuViewWillShow:(PUMenuView *)menuView;
- (void)menuViewDidShow:(PUMenuView *)menuView;
- (void)menuViewWillHide:(PUMenuView *)menuView;
- (void)menuViewDidHide:(PUMenuView *)menuView;

@end


@interface PUMenuView : UIView

@property (nonatomic, weak) NSObject<PUMenuViewDelegate> *delegate;
@property (nonatomic, weak) NSObject<PUMenuViewDataSource> *dataSource;

@property (nonatomic, strong) UIView *backgroundView;

//behavior
@property (nonatomic) BOOL menuShouldHideAfterSelection;
@property (nonatomic) BOOL menuShouldHideOnTapOut;

//state
@property (nonatomic) BOOL isAnimationPresenting;
@property (nonatomic) BOOL isHidden;
@property (nonatomic) BOOL readyForShowing;

//animation (show & hide)
@property (nonatomic) CGFloat animationUnitDelay;
@property (nonatomic) CGFloat animationBackgroundDismissDelay;
@property (nonatomic) CGFloat animationBackgroundDuration;
@property (nonatomic) CGFloat animationSpringDamping;
@property (nonatomic) CGFloat animationDuration;
@property (nonatomic) NSArray *animationOrder;
@property (nonatomic) AnimationDirection animationDirection;

//layout
@property (nonatomic) CGFloat itemWidthHeightRatio;
@property (nonatomic) NSInteger numberOfColumns;
@property (nonatomic) CGFloat itemSideLengthMultiplier;
@property (nonatomic) CGFloat verticalSpaceMultiplier;
@property (nonatomic) CGFloat horizontalMarginMultiplier;
@property (nonatomic, readonly) CGFloat horizontalSpacingMultiplier;

//userinfo
@property (nonatomic) NSMutableDictionary *userInfo;

- (void)show;
- (void)hide;

@end