//
//  SketchInterface.h
//  SketchyPlugin
//
//  Created by Rob Visentin on 10/24/17.
//  Copyright © 2017 Brian King. All rights reserved.
//

@import AppKit;

@protocol MSDocumentInterface;
@protocol MSMainSplitViewControllerInterface;
@protocol MSInspectorStackViewInterface;
@protocol MSLayerInterface;
@protocol MSLayerArrayInterface;

@interface SketchInterface : NSObject

+ (id<MSDocumentInterface>)currentDocument;

@end

#pragma mark - MSDocument

@protocol MSDocumentInterface

@property (nonatomic, readonly) id<MSMainSplitViewControllerInterface> splitViewController;

@property (nonatomic, readonly) id<MSLayerArrayInterface> selectedLayers;

@end

#pragma mark - MSMainSplitViewController

@protocol MSMainSplitViewControllerInterface

@property (nonatomic, readonly) NSView *inspectorView;

@end

#pragma mark - MSInspectorStackView

@protocol MSInspectorStackViewInterface

@property (nonatomic, readonly) NSArray<NSViewController *> *sectionViewControllers;

- (void)reloadWithViewControllers:(NSArray<NSViewController *> *)viewControllers;

@end

#pragma mark - MSLayer

@protocol MSLayerInterface

@property (strong, nonatomic) NSDictionary *userInfo;

@end

#pragma mark - MSLayerArray

@protocol MSLayerArrayInterface

@property (strong, nonatomic) NSArray<id<MSLayerInterface>> *layers;

@end
