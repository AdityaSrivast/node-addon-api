'use strict';
const buildType = process.config.target_defaults.default_configuration;
const assert = require('assert');

test(require(`./build/${buildType}/binding.node`));
test(require(`./build/${buildType}/binding_noexcept.node`));

function test(binding) {
  const {
    IsPalindrome
  } = binding.palindrome;

  assert.strictEqual(IsPalindrome('abcba'), "Palindrome");
  assert.strictEqual(IsPalindrome('random'), "Not a Palindrome");
  assert.strictEqual(IsPalindrome('malayalam'), "Palindrome");
  assert.strictEqual(IsPalindrome(21421), "Not a string");
}
