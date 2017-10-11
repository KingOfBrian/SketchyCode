//
//  AssignmentExpression.swift
//  SketchyCode
//
//  Created by Brian King on 10/11/17.
//  Copyright © 2017 Brian King. All rights reserved.
//

import Foundation

// An assignment expression is attached to a variable declaration.
struct AssignmentExpression: Expression {
    let to: VariableRef
    let expression: Expression

    func generate(in scope: Scope, context: GeneratorContext) throws {
        try expression.generate(in: scope, context: context)
    }

    func transform(variable from: VariableRef, to: VariableRef) -> Expression {
        return AssignmentExpression(
            to: to.transform(from: from, to: to),
            expression: expression.transform(variable: from, to: to))
    }
}

extension AssignmentExpression {
    init(to: VariableRef, expression parts: SyntaxPart...) {
        self.init(to: to, expression: BasicExpression(parts: parts))
    }
}
