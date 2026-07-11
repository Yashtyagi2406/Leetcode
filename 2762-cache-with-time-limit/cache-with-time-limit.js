var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();

    const exists =
        this.cache.has(key) &&
        this.cache.get(key).expire > now;

    this.cache.set(key, {
        value: value,
        expire: now + duration
    });

    return exists;
};

/** 
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) return -1;

    const item = this.cache.get(key);

    if (item.expire <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return item.value;
};

/** 
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let cnt = 0;

    for (const [key, item] of this.cache) {
        if (item.expire > now)
            cnt++;
        else
            this.cache.delete(key);
    }

    return cnt;
};