const fs = require("fs");

const src = ".env.react";
const dest = ".env";

if (!fs.existsSync(src)) {
  console.error(`❌ Cannot find ${src}`);
  process.exit(1);
}

fs.copyFileSync(src, dest);
console.log(`✅ Copied ${src} to ${dest}`);
